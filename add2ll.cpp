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

Node* add2Nos(Node* head1, Node* head2){
    Node* dummyNode = new Node(-1);
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* curr = dummyNode;
    int carry = 0;

    while(temp1 != NULL || temp2 != NULL){
        int sum = carry;
        if(temp1){
            sum += temp1->data;
        }
        if(temp2){
            sum += temp2->data;
        }
        Node* newNode = new Node(sum % 10);
        
        carry = sum / 10;

        curr->next = newNode;
        curr = curr->next;

        if(temp1){
            temp1 = temp1->next;
        }
        if(temp2){
            temp2 = temp2->next;
        }
    }
    if(carry){
        Node* newNode = new Node(carry);
        curr->next = newNode; 
    }
    return dummyNode->next;
}

int main(){

    return 0;
}