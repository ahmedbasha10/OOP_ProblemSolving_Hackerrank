#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/*  Start of Solution */
class Person{
    protected:
        string name;
        short age;
    public:
        virtual void getdata() = 0;
        virtual void putdata() = 0;
};

class Professor : public Person{
    private:
        int publications;
        static int cur_id;
        int id = cur_id;
    public:
        Professor(){
            ++cur_id;
        }
        virtual void getdata() override{
            cin >> name >> age >> publications;
        }
        virtual void putdata() override{
            cout << name << " " << age << " " << publications << " " << id << endl; 
        } 
};

class Student : public Person{
    private:
        int marks[6];
        static int cur_id;
        int id = cur_id;
    public:
        Student(){
            ++cur_id;
        }
        virtual void getdata() override{
            cin >> name >> age;
            for(int i = 0; i < 6; ++i){
                cin >> marks[i];
            }
        }
        virtual void putdata() override{
            int sumOfMarks = 0;
            for(int i = 0; i < 6; ++i){
                sumOfMarks += marks[i];
            }
            cout << name << " " << age << " " << sumOfMarks << " " << id << endl;
        }
};

int Professor::cur_id = 1;
int Student::cur_id = 1;

/*  End of Solution */

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
