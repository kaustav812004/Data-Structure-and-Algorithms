#include<bits/stdc++.h>
using namespace std;

int csum(vector<int>& nums, int l, int mid, int h){
        int lsub = INT_MIN, sum = 0;
        for(int i = mid; i >= l; i--){
            sum += nums[i];
            lsub = max(lsub, sum);
        }
        sum = 0;
        int rsub = INT_MIN;
        for(int i = mid+1; i <= h; i++){
            sum+=nums[i];
            rsub = max(rsub, sum);
        }
        return lsub+rsub;
    }
    int maxSub(vector<int>& nums, int l, int h){
        if(l == h) return nums[l];

        int mid = (l+h)>>1;
        int lmax = maxSub(nums, l, mid);
        int rmax = maxSub(nums, mid+1, h);
        int cmax = csum(nums, l, mid, h);

        return max(lmax, max(rmax, cmax));
    }
    int maxSubArray(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        return maxSub(nums, l, h);
    }

// int maxSubArray(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 0);
//         dp[0] = nums[0];
//         int sum = dp[0];
//         for(int i = 1; i < n; i++){
//             if(dp[i-1] < 0) dp[i] = nums[i];
//             else{
//                 dp[i] = nums[i]+dp[i-1];
//             }
//             sum = max(sum, dp[i]);
//         }
//         return sum;
//     }

int main(){
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(arr);
}