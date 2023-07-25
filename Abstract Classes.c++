#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

/* Start Of Solution */
class LRUCache : public Cache{
    public:
        LRUCache(int capacity){
            cp = capacity;
        };

        virtual void set(int key, int value) override{
            Node* newNode = new Node(key, value);
            if(mp.empty()){  
                head = newNode;
                tail = newNode;
                mp[key] = newNode;
            }
            else if(mp.size() < cp){
               if(mp.find(key) != mp.end()){
                  mp[key]->value = value;
                  newNode->prev = tail;
                  newNode->next = nullptr;
                  tail->next = newNode;
                  tail = newNode;
               }
               else{
                  newNode->prev = tail;
                  newNode->next = nullptr;
                  tail->next = newNode;
                  tail = newNode;
                  mp[key] = newNode;
               }
            }else if(mp.size() >= cp){
               mp.erase(head->key);
               head = head->next;
               delete head->prev;
               newNode->prev = tail;
               newNode->next = nullptr;
               tail->next = newNode;
               tail = newNode;
               mp[key] = newNode;
            }      
        };   
        
        virtual int get(int key) override{
            if(mp.count(key) == 0){
               return -1;
            }
            return mp[key]->value;
        };
};
/* End Of Solution */

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
