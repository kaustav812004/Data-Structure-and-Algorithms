#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }

};

Node* reverseLL(Node* head){
    Node* temp = head; 
    Node* prev = NULL;

    while(temp != NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

void PrintList(Node *head) // Function to print the LinkedList
{
    Node *curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->data << "-->";
    cout << "null" << endl;
}


int main(){
    vector<int> arr = {1, 3, 2, 5};
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    PrintList(head);
    head = reverseLL(head);
    PrintList(head);
    return 0;
}