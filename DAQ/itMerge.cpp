#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& A, int l, int mid, int h){
    vector<int> B(A.size());
    int i = l, k = l, j = mid+1;
    while(i <= mid && j <= h){
        if(A[i] < A[j]){
            B[k++] = A[i++];
        }
        else{
            B[k++] = A[j++];
        }
    }
    for(; i <= mid; i++) B[k++] = A[i++];
    for(; j <= h; j++) B[k++] = A[j++];
    for(int i = l; i <= h; i++) A[i] = B[i];
}
void MergeSort(vector<int>& arr){
    int n = arr.size();
    int lastsize = 0;
    for(int size = 1; size <= n/2; size*=2){
        lastsize = size;
        for(int l = 0, h = 2*size-1; h <= n-1; l = h+1, h = l+2*size-1){
            int mid = (l+h)>>1;
            merge(arr, l, mid, h);
        }
    }
    if(2*lastsize < n){
        merge(arr, 0, 2*lastsize-1, n-1);
    }
}

int main(){
    vector<int> arr = {70, 20, 30, 50, 10, 60, 40};
    MergeSort(arr);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}