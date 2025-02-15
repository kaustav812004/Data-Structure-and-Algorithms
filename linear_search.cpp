#include<bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int n, int k){
    for(int i = 0; i < n; i++){
        if(arr[i] == k){
            return i;
        }
    }
    return -1;
}

int main(){
    int arr[] = { 1, 4, 6, 2, 8, 5, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<linear_search(arr, n, 5)<<endl;
    cout<<linear_search(arr, n, 11);
    return 0;
}


//T.C = O(n)