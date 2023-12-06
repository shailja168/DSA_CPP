#include <bits/stdc++.h>
using namespace std; 

class student{
    public:
    string name;
    int age;
    bool gender;  //0 = male, 1 = female

    void printinfo(){
        cout<<"NAME = "<<name<<endl;;
        cout<<"AGE = "<<age<<endl;
        cout<<"GENDER = "<<gender<<endl;
    }
};

int main() {
    
    student a;                 //single object
    a.name = "Tim";
    a.age = 20;
    a.gender = 0;
    
    student arr[3];            //array of objects
    for (int i = 0; i < 3; i++){
        cout<<"NAME = ";
        cin>>arr[i].name;
        cout<<"AGE = ";
        cin>>arr[i].age;
        cout<<"GENDER = ";
        cin>>arr[i].gender;
    }
    for (int i = 0; i < 3; i++){   
        arr[i].printinfo();
    }    

    return 0;
}