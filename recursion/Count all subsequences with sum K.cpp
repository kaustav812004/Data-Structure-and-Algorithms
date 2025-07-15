#include<bits/stdc++.h>
using namespace std;

int helper(int idx, int k, vector<int>& arr, int n, int sum){
		if(idx == n){
            if(sum == k){
                return 1;
            }
            return 0;
        }
        sum += arr[idx];
    	int l = helper(idx+1,k, arr, n, sum);
        sum -= arr[idx];
        int r = helper(idx+1, k, arr, n, sum);
        return (r+l);
    }
int findWays(vector<int>& arr, int k)
{
    int n = arr.size();
	return helper(0, k, arr, n, 0);
}


