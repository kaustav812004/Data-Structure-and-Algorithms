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

//function to print linked list
void printLL(Node* head){
    Node* temp = head;
    while(head != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int checkifPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val){
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

Node* convertArrtoLL(vector<int>arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node (arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;

}

//function to insert a new node at the head of the linked list
Node* inserthead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

Node* inserttail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    } 
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node* insertK(Node* head, int val, int k){
    if(head == NULL){
        if(k == 1){
            return new Node(val);
        }
        else{
            return head;
        }
    }
    if(k == 1){
        return new Node(val, head);
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == (k - 1)){
            Node* x = new Node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;

}

//function to insert val before el
Node* insertval(Node* head, int val, int el){
    if(head == NULL){
        return NULL;
    }
    if(head->data == el){
        return new Node(val, head);
    }
    Node* temp = head;
    bool found = false;
    while(temp->next != NULL){
        if(temp->next->data == el){
            Node* x = new Node(val, temp->next);
            temp->next = x;
            found = 1;
            break;
        }
        temp = temp->next;
    }
    // if(found == false){

    // }
    return head;
}


//function to delete elements in a Linked List
Node* removehead(Node* head){
    if(head == NULL){
        return head;
    }
    Node* temp = head;
    head = head->next;

    free(temp);  //delete temp

    return head;
}

Node* removetail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;

    return head;
}

Node* removeK(Node* head, int k){
    if(head == NULL){
        return head;
    }
    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if( cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* removeVal(Node* head, int val){
    if(head == NULL){
        return head;
    }
    if(head->data = val){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data = val){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head; 
}

int main(){
    vector<int> arr = {12, 5, 6, 8};
    int val = 100;
    int value = 90;
    //Creating a linked list with initial elements from the array
    // Node* head = new Node(arr[0]);
    // head->next = new Node(arr[1]);
    // head->next->next = new Node(arr[2]);
    // head->next->next->next = new Node(arr[3]);


    Node* head = convertArrtoLL(arr);
    head = inserthead(head, val);
    printLL(head);
    cout<<endl;
    head = inserttail(head, value);
    printLL(head);
    cout<<endl;
    head = insertK(head, 102, 4);
    printLL(head);
    cout<<endl;
    head = insertval(head, 105, 8);
    printLL(head);
    cout<<endl;
    head = removehead(head);
    printLL(head);
    cout<<endl;
    head = removetail(head);
    printLL(head);
    cout<<endl;
    head = removeK(head, 4);
    //head = removeVal(head, 105);
    cout<<checkifPresent(head, 105)<<endl;
    printLL(head);
    cout<<endl;

}