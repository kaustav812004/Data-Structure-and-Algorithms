#include<bits/stdc++.h>
using namespace std;
struct StackNode{
    int data;
    StackNode* next;
    StackNode(int d){
        data = d;
        next = nullptr;
    }
};

struct Stack{
    StackNode* top;
    int size;
    Stack(){
        top = nullptr;
        size = 0;
    }
    void push(int x){
        StackNode* ele = new StackNode(x);
        ele->next = top;
        top = ele;
        cout<<"Element push"<<'\n';
        size++;
    }
    int pop(){
        if(top == NULL){
            return -1;
        }
        int topdata = top->data;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        size--;
        return topdata;
    }
    int stackSize(){
        return size;
    }
    bool stackIsEmpty() {
        return top == NULL;
      }
      int stackPeek() {
        if (top == NULL) return -1;
        return top -> data;
      }
      void printStack() {
        StackNode * current = top;
        while (current != NULL) {
          cout << current -> data << " ";
          current = current -> next;
        }
      }
};

int main() {
    Stack s;
    s.push(10);
    cout << "Element popped: " << s.pop() << "\n";
    cout << "Stack size: " << s.stackSize() << "\n";
    cout <<"Stack empty or not? "<<s.stackIsEmpty()<<"\n";
    cout << "stack's top element: " << s.stackPeek() << "\n";
    return 0;
  }