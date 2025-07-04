#include<iostream>
using namespace std;


class heap{
    public:
    int arr[100];
    int size = 0;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    
    void insert(int val){
        size++;
        int index = size;
        arr[index] = val;

        while(index>1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return ;
            }
        }
    }

    void deletefromHeap(){
        if(size == 0){
            cout<<"Nothing to delete"<<endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        //take root node to its correct position
        int i = 1;
        while(i<size){
            int leftIdx = 2*i;
            int rightIdx = 2*i + 1;

            if(leftIdx < size && arr[i] < arr[leftIdx] ){
                swap(arr[i], arr[leftIdx]);
                i = leftIdx;
            }
            else if(rightIdx < size && arr[i] < arr[rightIdx] ){
                swap(arr[i], arr[rightIdx]);
                i = rightIdx;
            }
            else{
                return;
            }
        }
    }
    void print(){
        for(int i = 1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

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

int main(){

    heap h;
    h.insert(50);
    h.insert(60);
    h.insert(55);
    h.insert(51);
    h.insert(70);
    h.insert(58);

    h.print();

    h.deletefromHeap();

    h.print();

//heapify implement

    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i>0; i--){
        heapify(arr, n, i);
    }

    for(int i = 1; i<=n; i++){
        cout<<arr[i]<<" ";
    } cout<<endl;


    return 0;
}