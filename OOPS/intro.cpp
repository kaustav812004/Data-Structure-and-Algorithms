#include<bits/stdc++.h>
using namespace std;
//Accessing private elements 
class Hero{
    private:
    int health;
    public:
    char level;

    Hero(){
        cout<<"Default constructor"<<endl;
    }
    Hero(char l){
        this->level = l;
    }
    
    //paremetreized constructor
    Hero(int h, char l){
        this->health = h;
        this->level = l;
        cout<<this<<endl;
    }
    //this stores address of current object
    
    //copy constructor (all are present by deafault but as soon as we create any constructor the default is removed)
    Hero(Hero& x){
        this->level = x.level;
        this->health = x.health;
    }
    int gethealth(){
        return health;
    }
    void sethealth(int i){
        health = i;
    }
    void print(){
        cout<<"Health is : "<<health<<endl;
        cout<<"Level is : "<<level<<endl;
    }
};
int main(){
    // Hero Kaustav;
    Hero* Kaustav = new Hero(100, 'A');
    // Kaustav->sethealth(100);
    // Kaustav->level = 'A';
    // cout<<&Kaustav<<endl;
    // cout<<"Health is : "<<Kaustav->gethealth()<<endl;
    // cout<<"Level is : "<<Kaustav->level;
    Kaustav->print();
    Hero* Rishit = new Hero(*Kaustav);  //copy constructor
    Rishit->print();
    Hero Saurav(100, 'B');
    Saurav.print();
    Hero Alex(Saurav);
    Alex.print();
    return 0;
}