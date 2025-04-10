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
void PrintList(Node *head) // Function to print the LinkedList
{
    Node *curr = head;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->data << "-->";
    cout << "null" << endl;
}
Node* head, * tail;
void InsertatLast(int value) // Function for creating a LinkedList
{

    Node *newnode = new Node(value);
    if (head == nullptr)
        head = newnode, tail = newnode;
    else
        tail = tail->next = newnode;
}
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

bool isPalindrome(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseLL(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second != NULL){
        if(first->data != second->data){
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
}

int main(){
    InsertatLast(1);
    InsertatLast(2);
    InsertatLast(3);
    InsertatLast(3);
    InsertatLast(5);
    InsertatLast(1);
    PrintList(head);
    cout<<endl;

    cout<<isPalindrome(head);

    return 0;
}