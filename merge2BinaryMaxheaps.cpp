#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> arr, int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> a, vector<int> b){

    //step1: merge 2 vectors
    int n = a.size();
    int m = b.size();

    vector<int> ans;
    ans.push_back(-1);
    for(auto i:a){
        ans.push_back(i);
    }
    for(auto i:b){
        ans.push_back(i);
    }

    //step2: build heap
    int size = ans.size();

    for(int i = (size/2); i > 0; i--){
        heapify(ans, size, i);
    }

    return ans;


}

int main(){
    vector<int> arr1 = { 54, 53, 55, 52, 50};
    vector<int> arr2 = {70, 58, 60, 51, 57};

    vector<int> c = mergeHeaps(arr1, arr2);

    for(int i = 1; i<c.size(); i++){
        cout<<c[i]<<" ";
    }cout<<endl;

    return 0;
}
