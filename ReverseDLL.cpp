#include<bits/stdc++.h>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    Node* back;
    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};
Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* prev = nullptr;
    Node* current = head;
    while(current != NULL){
        prev = current->back;
        current->back = current->next;
        current->next =  prev;
        current = current->back;
    }
    return prev->back;
}

Node* convertarr2DLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i = 1; i < arr.size(); i++){
        Node*temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void printDLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;

    }
}

int main(){
    vector<int> arr = {1, 4, 6, 8, 3};
    Node* head = convertarr2DLL(arr);
    printDLL(head);
    cout<<endl;
    head = reverseDLL(head);
    printDLL(head); 
    return 0;
}