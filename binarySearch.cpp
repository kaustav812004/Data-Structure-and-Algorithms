#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>&nums, int target) {
    int n = nums.size();
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = (low + high) / 2;
        if(nums[mid] == target) return mid;
        else if (target > nums[mid]) {
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> a = {3, 4, 6, 8, 9, 12, 14, 17, 20, 25};
    int target = 20;
    int idx = binarySearch(a, target);
    if(idx == -1){
        cout<<"The target is not present"<<endl;
    }
    else{
        cout<<"The target is at index: "<<idx<<endl;
    }
    return 0;
}