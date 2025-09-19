#include<iostream>
using namespace std;

//Method Overriding 

class Animal{

    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};

class Dog: public Animal{

    public:
    void speak(){
        cout<<"Barking"<<endl;
    }
};


int main(){
    Dog d;
    d.speak();


    return 0;
}
