#include<bits/stdc++.h>
using namespace std;
#include "class.hpp";
int Hero::timeTocomplete =  5;


// For static objects destructor is automatically called
//but for dynamically allocated objs call destructor manually

int main(){
    Hero* Alex = new Hero(100,'A');
    Alex->name = "Alex";
    Alex->print();
    Hero* Gabriel = new Hero(*Alex);
    Gabriel->print();
    Hero* Kaustav = new Hero(100, 'B');
    Kaustav->name = "Kaustav";
    Kaustav->print();
    Alex = Kaustav;
    Alex->print();
    cout<<Hero::timeTocomplete<<endl;
    Alex->timeTocomplete = 10;
    cout<<Alex->timeTocomplete<<endl;
    delete Alex;
    delete Kaustav;
    delete Gabriel;
    return 0;
}