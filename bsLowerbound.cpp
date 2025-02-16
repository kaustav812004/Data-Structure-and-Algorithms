#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> nums, int n, int x){
    int low = 0, high = n-1;
    int ans = n;

    while(low <= high) {
        int mid = (low+high) / 2;

        if(nums[mid] >= x){
            ans = mid;
            high = mid - 1;
        }

        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3, 5, 7, 10, 23};
    int x = 9;
    int n = arr.size();
    int idx = lowerBound(arr, n, x);
    cout<<"The lower bound is the index: "<< idx<<endl;
    return 0;
}


// t.c = O(logn)