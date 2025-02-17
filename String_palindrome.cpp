#include<bits/stdc++.h>
using namespace std;
bool isAlphaNum(char ch)
{
    if ((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
    {
        return true;
    }
    return false;
}
bool isPalindrome(string s)
{
    int st = 0, end = s.length() - 1;
    while (st < end)
    {
        if (!isalnum(s[st]))
        {
            st++;
            continue;
        }
        if (!isalnum(s[end]))
        {
            end--;
            continue;
        }
        if (tolower(s[st] != s[end]))
        {
            return false;
        }
        else
        {
            st++, end--;
        }
    }
    return true;
}

int main(){
    isPalindrome("madam");
    return 0;
}