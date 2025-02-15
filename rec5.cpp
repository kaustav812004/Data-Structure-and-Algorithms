#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n == 0){
        return 1;
    }
    int mul = 1;
    for(int i = 1; i <= n; i++) {
        mul = mul*i;
    }

    return mul;
}

int main(){
    cout<<fact(5);
    return 0;
}