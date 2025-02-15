#include <bits/stdc++.h>
using namespace std;


// void rotate(vector<int>& nums, int k) {
//         int n = nums.size();
//         k = k%n;
//         reverse(nums.begin(), nums.end()-k);
//         reverse(nums.end()-k, nums.end());
//         reverse(nums.begin(), nums.end());
//     }

void Reverse(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void Rotateright(int arr[], int n, int k)
{
    // Reverse first n-k elements
    Reverse(arr, 0, n - k - 1);
    // Reverse last k elements
    Reverse(arr, n - k, n - 1);
    // Reverse whole array
    Reverse(arr, 0, n - 1);
}

void RotateLeft(int arr[], int n, int k)
{
    // Reverse first n-k elements
    Reverse(arr, 0, k - 1);
    // Reverse last k elements
    Reverse(arr, k, n - 1);
    // Reverse whole array
    Reverse(arr, 0, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int temp[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    int k = 2;
    Rotateright(arr, n, k);
    cout << "After Rotating the k elements to right ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    RotateLeft(temp, n, k);
    cout << "After Rotating the k elements to left ";
    for (int i = 0; i < n; i++)
        cout << temp[i] << " ";
    cout << endl;
    return 0;
}