#include<bits/stdc++.h>
using namespace std;

int maxconsecutive1s(vector<int>& arr){
    int count = 0;
    int maxi = 0;
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(arr[i] == 1){
            count++;
        }
        else{ count = 0;}

        maxi = max(maxi, count);
    }
    return maxi;

}

int main(){
    vector<int> nums = { 1, 1, 0, 1, 1, 1};
    cout<<maxconsecutive1s(nums);
    return 0;
}