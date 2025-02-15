#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n)
{
    // if (arr.empty())
    // {
    //     return 0;
    // }
    // int n = sizeof(arr)/sizeof(arr[0]);
    int k = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            arr[k] = arr[i];
            k++;
        }
    }
    return k;
}

int main(){
    int ar[] = {1,1,2,2,3,5,6,8,9,9,9,10,10};
    cout<<removeDuplicates(ar, sizeof(ar)/sizeof(ar[0]));    
    return 0;
}