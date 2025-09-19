#include<bits/stdc++.h>
#include "class.hpp"
using namespace std;

int Hero::timeTocomplete = 10;
int main(){
    cout<<Hero::random();
    return 0;
}

//always use static members inside static functions
// also static functions and members always need 
// scope resolution operator outside the class