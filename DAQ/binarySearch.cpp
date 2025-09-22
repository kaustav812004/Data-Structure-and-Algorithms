#include<bits/stdc++.h>
using namespace std;

int binS(vector<int>& arr, int l, int h, int key){
    if(l > h) return -1;
    int mid = (l+h)>>1;
    if(arr[mid] == key) return mid;
    else if(arr[mid] > key){
        return binS(arr, l, mid-1, key);
    }
    else return binS(arr, mid+1, h, key);
}

int main(){
    vector<int> arr = {1, 5, 7, 9, 12, 23, 45, 56};
    cout<<binS(arr, 0, arr.size()-1, 23);
    return 0;
}