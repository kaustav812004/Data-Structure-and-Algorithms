#include<bits/stdc++.h>
using namespace std;

void num(int cnt, int n){
    if(cnt == n){
        cout<<cnt<<endl;
        return;
    }
    cout<<cnt<<endl;
    cnt++;
    num(cnt,n);
}

int main(){
    num(0,10);
    return 0;
}