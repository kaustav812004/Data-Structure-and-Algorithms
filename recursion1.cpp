#include<bits/stdc++.h>
using namespace std;


void copy(int count){
    if(count == 3)
        return;
    
    copy(count);    
    cout<<count<<endl;
    count++;

}

int main(){
    copy(1);
    return 0;
}