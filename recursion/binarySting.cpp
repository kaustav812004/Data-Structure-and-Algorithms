#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void helper(string s, int n, vector<string>& res){
        if(s.size() == n){
            res.push_back(s);
            return;
        }
        helper(s+'1', n, res);
        if(s.empty() || s.back() != '0'){
            helper(s+'0', n, res);
        }
    }
    vector<string> validStrings(int n) {
        vector<string> res;
        helper("", n, res);
        return res;
    }
};