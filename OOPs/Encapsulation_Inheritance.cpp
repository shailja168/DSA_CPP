#include <bits/stdc++.h>
using namespace std; 

/*
Inheritance- inheriting from other classes
Types-
1) Single Inheritance: class A -> class B
2) Multiple Inheritance: class A ->  class C  <- class B
3) Multi level Inheritance: class A ->  class B  -> class C
4) Hybrid Inheritance
5) Hierarchical Inheritance
*/

/*
Encapsulation- hiding sensitive data from user
Access modifiers- public, private, protected
*/

class abc{
    public:
        int a;
        void funca(){
            cout<<"func a \n";
        }
    private:
        int b;
        void funcb(){
            cout<<"func b \n";
        }
    protected:
        int c;
        void funcc(){
            cout<<"func c \n";
        }
};

int main() {
    
    abc obj;

    obj.funca();
    //obj.funcb();  //shows error
    //obj.funcc();  //shows error

    return 0;
}



