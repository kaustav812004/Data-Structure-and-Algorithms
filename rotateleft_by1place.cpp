
#include<bits/stdc++.h>

using namespace std;
void solve(vector<int> arr) {
    int n = arr.size();
  int temp = arr[0]; // storing the first element of array in a variable
  for (int i = 1; i < n; i++) {
    arr[i-1] = arr[i];
  }
  arr[n - 1] = temp; // assigned the value of variable at the last index
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
  solve(arr);
}

