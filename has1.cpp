#include<bits/stdc++.h>
using namespace std;

//Check the no of occurences of an int in an array(number hashing)

int main() {
    int n;
    cout<<"Enter length of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements"<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    //precompute
    int hash[13] = {0};
    for(int i =0; i<n; i++){
        hash[arr[i]] += 1;
    }

    int q;
    cout<<"Enter how many numbers you want to check for repitition: ";
    cin>>q;
    cout<<"Enter the numbers:"<<endl;
    while(q--){
        int num;
        cin>>num;
        //fetch
        cout<< hash[num]<<endl;
    }
    
    return 0;
}