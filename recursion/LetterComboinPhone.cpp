#include<bits/stdc++.h>
using namespace std;


    void solve(string& digits, string& output, int idx, vector<string>& ans, string mapping[]){
        if(idx == digits.size()){
            ans.push_back(output);
            return;
        }
        int num = digits[idx] - '0';
        string value = mapping[num];

        for(int i = 0; i < value.size(); i++){
            output.push_back(value[i]);
            solve(digits, output, idx+1, ans, mapping);
            output.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0){
            return ans;
        }
        int idx = 0;
        string output;
        string mapping[10] = {"",    "",    "abc",  "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(digits, output, idx, ans, mapping);
        return ans;
    }


int main(){
    string digits;
    cin>>digits;
    vector<string> combo = letterCombinations(digits);
    cout<<"[";
    for(auto ch : combo){
        cout<<ch<<" ";
    }
    cout<<"]";
    return 0;
}