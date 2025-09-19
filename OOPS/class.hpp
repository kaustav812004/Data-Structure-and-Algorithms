#include<bits/stdc++.h>>
using namespace std;
class Hero{
    private:
    int health;
    public:
    string name;
    char level;
    static int timeTocomplete;

    Hero(){
        cout<<"Default constructor"<<endl;
    }
    Hero(char l){
        this->level = l;
    }
    
    Hero(int h, char l){
        this->health = h;
        this->level = l;
    }
    
    Hero(Hero& x){
        this->name = x.name;
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
        cout<<"[Name : "<<name<<", ";
        cout<<"Health is : "<<health<<", ";
        cout<<"Level is : "<<level<<"]"<<endl;
    }
    static int random(){
        return timeTocomplete;
    } 

    ~Hero(){
        cout<<"Destroyed"<<endl;
    }
};