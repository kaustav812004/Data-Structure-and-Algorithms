#include<iostream>
using namespace std;

// function overloading
class A{
    public:
    void sayhello(){
        cout<<"Hello"<<endl;
    }

    void sayhello(string name){
        cout<<"Hi "<<name<<endl;
    }

    int sayhello(char name, int n){
        cout<<"Hi "<<name<<endl;
        return n;
    }
};

//operator overloading
class B{
    public:
    int a;
    int b;

    public:
    int add(){
        return a+b;
    }

    void operator+ (B &obj){
        int val1 = this->a;
        int val2 = obj.a;
        cout<<"output: "<<val2-val1<<endl;
    }
};



int main(){
    A obj;
    obj.sayhello();
    obj.sayhello("Kaustav");
    cout<<obj.sayhello('k', 2)<<endl;

    B obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;
    obj1 + obj2;
    return 0;
}