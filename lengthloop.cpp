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
int findLength(Node* slow, Node* fast){
    int cnt = 1; 
    fast = fast->next;
    while(slow!=fast){
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

int lengthloop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(head != NULL && head->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            return findLength(slow, fast);
        }
    }
    return 0;
}

int main(){
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = third; 

cout<<lengthloop(head);

    return 0;
}