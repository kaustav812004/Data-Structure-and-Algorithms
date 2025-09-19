#include<iostream>
using namespace std;

class A{
    public:
    void func1(){
        cout<<"Inside func1"<<endl;
    }
};

class B: public A{

    public:
    void func2(){
        cout<<"Inside func2"<<endl;
    }
};

class C: public A{
    public:
    void func3(){
        cout<<"Inside func3"<<endl;
    }
};

int main(){

    A obj1;
    B obj2;
    C obj3;

    cout<<"Inside obj1"<<endl;
    obj1.func1();
    
    cout<<"Inside obj2"<<endl;
    obj2.func1();
    obj2.func2();

    cout<<"Inside obj3"<<endl;
    obj3.func3();
    obj3.func1();

    return 0;
}