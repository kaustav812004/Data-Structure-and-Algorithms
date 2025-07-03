#include<bits/stdc++.h>
using namespace std;

 int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;


        for(int i = 0; i < k; i++){
            pq.push(nums[i]);
        }
        int n = nums.size();

        for(int i = k; i < n; i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        int ans = pq.top();
        return ans;
    }

int main(){
    
    vector<int> arr = { 12, 3, 5, 7, 19 };
    int K = 3;

    cout << findKthLargest(arr, K);
    return 0;
}