#include <bits/stdc++.h>
using namespace std; 

/*
Polymorphism- many forms of a single data
Types-
1) Compile Time 
    (i) Function Overloading
    (ii) Operator Overloading
2) Run Time
    (i) Virtual Functions
*/

//   Function Overloading

class apnacollege
{
public:
    void func(){
        cout<<"func with no argument\n";
    }
    void func(int n){
        cout<<"func with int argument\n";
    }
    void func(double x){
        cout<<"func with double argument\n";
    }
};

// Operator Overloading

class Complex
{
    int real, imag;
    public:
        Complex(int r=0, int i=0){
            real = r;
            imag = i;
        }

    Complex operator + (Complex const &obj){
        Complex res;
        res.imag = imag + obj.imag;
        res.real = real + obj.real;
        return res;
    }  

    void display(){
        cout<<real<<" + i"<<imag<<endl;
    }
};

// Virtual Functions

class base
{
public:
    virtual void print(){
        cout<<"this is base class's print function\n";
    }
    void display(){
        cout<<"this is base class's display function\n";
    }
};

class derived: public base
{
public:
    void print(){
        cout<<"this is derived class's print function\n";
    }
    void display(){
        cout<<"this is derived class's display function\n";
    }
};

int main() {

    // Function Overloading
    
    apnacollege obj;

    obj.func();
    obj.func(6);
    obj.func(4.5);

    // Operator Overloading

    Complex c1(12,7), c2(6,7);
    Complex c3 = c1 + c2;
    c3.display();

    // Virtual Functions

    base *baseptr;
    derived d;
    baseptr = &d;  //virtual functions will not run 

    baseptr -> print();
    baseptr -> display();

    return 0;
}