#include<bits/stdc++.h>
using namespace std;

void sum(int n){
    int cnt = 0;
    for(int i=0; i<=n; i++) {
        cnt+=i;
    }
    cout<<"The sum of first "<<n<<" numbers is: "<<cnt;
}

int main(){
    sum(10);
    return 0;
}