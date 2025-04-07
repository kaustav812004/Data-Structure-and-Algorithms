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

Node* SegragateOddEven(Node* head){
    Node* oddhead = new Node(-1);
    Node* evenhead = new Node(-1);
    Node* oddtail = oddhead;
    Node* eventail = evenhead;
    Node* curr = head, *temp;

    while(curr){
        temp = curr;
        curr = curr->next;
        temp->next = nullptr;

        if(temp->data % 2 == 1){
            oddtail->next = temp;
            oddtail = temp;
        }
        else{
            eventail->next = temp;
            eventail = temp;
        }
    }
    eventail->next = oddhead->next;

    return evenhead->next;

}
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

int main(){
    InsertatLast(1);
    InsertatLast(2);
    InsertatLast(3);
    InsertatLast(4);
    InsertatLast(5);
    InsertatLast(12);
    InsertatLast(19);
    cout << "Initial LinkedList : " << endl;
    PrintList(head);
    Node *newHead = SegragateOddEven(head);
    cout << "LinkedList After Segregration " << endl;
    PrintList(newHead);
    return 0;
}