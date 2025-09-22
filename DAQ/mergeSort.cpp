#include<bits/stdc++.h>
using namespace std;

// void merge(vector<int>& arr, int l, int mid, int r){
//     int n = mid+1-l;
//     int m = r-mid;
//     vector<int> L(n);
//     vector<int> R(m);

//     for(int i = 0; i < n; i++) L[i] = arr[l+i];
//     for(int i = 0; i < m; i++) R[i] = arr[mid+1+i];

//     int i = 0, j = 0, k = l;
//     while(i < n && j < m){
//         if(L[i] <= R[j]){
//             arr[k] = L[i];
//             i++;
//         }
//         else{
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }
//     while(i < n){
//         arr[k++] = L[i++];
//     }
//     while(j < m){
//         arr[k++] = R[j++];
//     }
// }

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

void mergeSort(vector<int>& arr, int l, int r){
    if(l >= r) return;
    int mid = (l+r)>>1;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

int main(){
    vector<int> arr = {70, 20, 30, 50, 10, 60, 40};
    mergeSort(arr, 0, arr.size()-1);
    for(int i : arr){
        cout<<i<<" ";
    }
    return 0;
}