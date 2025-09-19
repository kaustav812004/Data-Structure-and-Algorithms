#include<iostream>
using namespace std;

class A{
    public:
    void func(){
        cout<<"A"<<endl;
    }
};

class B{
    public:
    void func(){
        cout<<"B"<<endl;
    }
};

class C: public A, public B{
    public:
    void func(){
        cout<<"C"<<endl;
    }
};
 // use scope resolution operator to avoid inheritance ambiguity
int main(){
    C c;
    c.A::func();
    return 0;
}