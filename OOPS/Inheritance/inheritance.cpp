#include<iostream>
using namespace std;

class Human{
    public:
    int height;
    int weight;
    int age;

    public:
    int getAge(){
        return this->age;
    }
    void setWeight(int w){
        this->weight = w;
    }
};

class Male: public Human{
    
    public:
    string color;

    void sleep(){
        cout<<"Male sleeps"<<endl;
    }

};
class Female: protected Human{

    public:
    string color;
    void sleep(){
        cout<<"Female Sleeps"<<endl;
    }
    int getheight(){
        return this->height;
    }
};

int main(){
    Male obj1;
    obj1.color="black";
    obj1.setWeight(84);
    cout<<obj1.age<<endl;
    cout<<obj1.weight<<endl;
    cout<<obj1.height<<endl;
    cout<<obj1.color<<endl;
    obj1.sleep();

    Female f;
    cout<<f.getheight()<<endl;
}