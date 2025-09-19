#include<iostream>
using namespace std;

class Animal{

    public:
    int age;
    int weight;

    public:
    void voice(){
        cout<<"Voice"<<endl;
    }
};

class Human {
    public:
    string color;

    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};

//Multiple inheritance
class Hybrid: public Animal, public Human{

};

int main(){
    Hybrid h;
    h.speak();
    h.voice();
    return 0;
}