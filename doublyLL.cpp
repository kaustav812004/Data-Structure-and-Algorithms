#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;
    Node*back;
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

Node* removeHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    free(prev);
    return head;
}

Node* removeTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = NULL;
    tail->back = NULL;

    delete tail;

    return head;
}

Node* removeK(Node* head, int k){
    if(head == NULL){
        return NULL;
    }
    int cnt = 0;
    Node* kNode = head;
    while(kNode != NULL){
        cnt++;
        if(cnt == k){
            break;
        }
        kNode = kNode->next;
    }
    Node* prev = kNode->back;
    Node* front = kNode->next;

    if(prev == NULL && front == NULL){
        return NULL;
    }
    else if(prev == NULL){
        return removeHead(head);
    }
    else if(front == NULL){
        return removeTail(head);
    }
    prev->next = front;
    front->back = prev;

    kNode->next = NULL;
    kNode->back = NULL;
    delete kNode;

    return head;
}

void removeNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == NULL){
        prev->next = NULL;
        temp->back = NULL;
        free(temp);
        return ;
    }

    prev->next = front;
    front->back = prev;
    temp->next = temp->back = NULL;
    free(temp);
    return;
}

Node* insertHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;

    return newHead;
}

Node* insertbeforeTail(Node* head, int val){
    if(head->next == NULL){
        return insertHead(head, val);
    }
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    tail->back = newNode;
    prev->next = newNode;
    return head;
}
Node* insertBeforeK(Node* head, int k, int val){
    if(k == 1){
        return insertHead(head, val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != NULL){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    temp->back = newNode;
    prev->next = newNode;

    return head;
}
void insertbeforeNode(Node* node, int val){
    Node* prev = node->back;
    Node* newNode = new Node(val, node, prev);

    node->back = newNode;
    prev->next = newNode;

    return;
}
int main(){
    vector<int> arr = {2, 4, 6, 10, 14, 20, 17};
    Node* head = convertarr2DLL(arr);
    printDLL(head);
    cout<<endl;
    head = removeHead(head);
    printDLL(head);
    cout<<endl;
    head = removeTail(head);
    printDLL(head);
    cout<<endl;
    head = removeK(head, 4);
    printDLL(head);
    cout<<endl;
    removeNode(head->next->next);
    printDLL(head);
    cout<<endl;
    head = insertHead(head, 99);
    printDLL(head);
    cout<<endl;
    head = insertbeforeTail(head, 100);
    printDLL(head);
    cout<<endl;
    head = insertBeforeK(head, 4, 104);
    printDLL(head);
    cout<<endl;
    insertbeforeNode(head->next->next->next, 110);
    printDLL(head);
    cout<<endl;
    return 0;
}