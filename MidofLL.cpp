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
// Node* midNode(Node* head){
//     Node* temp = head;
//     int cnt = 0;
//     while(temp!=NULL){
//         cnt++;
//         temp = temp->next;
//     }
//     int mid = (cnt/2) + 1;
//     temp = head;
//     while(temp!=NULL){
//         mid -= 1;
//         if(mid == 0){
//             break;
//         }
//         temp = temp->next;
//     }
//     return temp;
// }


// Tortoise n Hare Algo
Node* midNode(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* midNodedel(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    fast = head->next->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}
int main(){
    InsertatLast(1);
    InsertatLast(2);
    InsertatLast(3);
    InsertatLast(4);
    InsertatLast(5);
    InsertatLast(7);
    PrintList(head);
    cout<<endl;
    Node* mid = new Node(-1); 
    mid = midNode(head);
    cout<<"Middle Node is: "<<mid->data<<endl;
    midNodedel(head);
    PrintList(head);
}