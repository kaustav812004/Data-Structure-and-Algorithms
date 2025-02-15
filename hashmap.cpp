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
    map<int, int> mpp;
    for(int i = 0; i<n; i++){
        //cin>>mpp[arr[i]]<<endl;
        mpp[arr[arr[i]]]++;
    }

    // for(auto it : mpp){
    //     cout<<it.first<<"->"<<it.second<<endl;  always gives an ordered and sorted 
    // }

    int q;
    cout<<"Enter how many numbers you want to check for repitition: ";
    cin>>q;
    cout<<"Enter the numbers:"<<endl;
    while(q--){
        int num;
        cin>>num;
        //fetch
        cout<<mpp[num]<<endl;
        
    }
    
    return 0;
}