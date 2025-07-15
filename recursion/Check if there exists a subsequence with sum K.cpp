#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
  
    bool helper(int idx, vector<int>& ans, int n, int k, vector<int>& arr, int sum){
        if(idx == n){
            if(sum == k){
                return true;
            }
            else return false;
        }
        ans.push_back(arr[idx]);
        sum += arr[idx];
        if(helper(idx+1, ans, n, k, arr, sum) == true) return true;
        ans.pop_back();
        sum -= arr[idx];
        if(helper(idx+1, ans, n, k, arr, sum) == true) return true;
        return false;
    }
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        vector<int> ans;
        int sum = 0;
        return helper(0, ans, n, k, arr, sum);
        
    }
};