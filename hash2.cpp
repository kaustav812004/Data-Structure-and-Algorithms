#include<bits/stdc++.h>
using namespace std;

//Character Hashing(lowercase)

int main(){
    string s;
     cout<<"Enter the string:"<<endl;
    cin>>s;

    //precompute
    int hash[26] = {0};
    for(int i = 0; i<s.size(); i++){
        hash[s[i] - 'a']++;
    }
    int q;
    cout<<"Enter how many characters you want to check for repitition: ";
    cin>>q;
    cout<<"Enter the characters:"<<endl;
    while(q--){
        char c;
        cin>>c;
        //fetch
        cout<<hash[c-'a']<<endl;
    }
    return 0;
}