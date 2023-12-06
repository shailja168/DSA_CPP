#include <bits/stdc++.h>
using namespace std; 

/*
Shallow Copy
The object and its copy, point to the same memory address. If you make a change
in its copy it gets changed in the main copy as well and vice versa.

Deep Copy
The object and its copy, point to different addresses in the memory. If you make a
change in its copy it will not get changed in the main copy and vice versa.

Default copy constructors do shallow copy 
User made copy constructors do deep copy
That is why User made copy constructors are preffered
*/

class student{
    string name;

    public:
    int age;
    bool gender;  //0 = male, 1 = female

    student(){
        cout<<"default constructor\n";
    } //default constructor

    student(string s, int a, bool g){  
        cout<<"parameterized constructor\n";  
        name = s;
        age = a;
        gender = g;
    } //parameterized constructor

    student(student &a){
        cout<<"copy constructor\n";
        name = a.name;
        age = a.age;
        gender = a.gender;
    } //copy constructor

    ~student(){
        cout<<"Destructor called\n";
    }

    void printinfo(){
        cout<<"NAME = "<<name<<endl;;
        cout<<"AGE = "<<age<<endl;
        cout<<"GENDER = "<<gender<<endl;
    }

    bool operator == (student &a){
        if(name==a.name && age==a.age && gender==a.gender)
            return true;
        return false;
    }   //operator overloading
};

int main() {
    
    student a("tom", 31, 1);  
    //a.printinfo();

    student b;

    student c = a;

    student d("jerry", 12, 0);

    if(c == d)
        cout<<"same\n";
    else
        cout<<"not same\n";

    return 0;
}