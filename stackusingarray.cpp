#include<bits/stdc++.h>
using namespace std;
struct Stack{
    public:
    int size;
    int top;
    int* arr;

    public:
    Stack(){
        size = 1000;
        top =-1;
        arr = new int[size];
    }

    int Top(){
        return arr[top];
    }

    void push(int val){
        top++;
        arr[top] = val;
        return;
    }

    int pop(){
        int x = arr[top];
        top--;
        return x;
    }

    int Size(){
        return top+1;
    }

};

int main(){
    Stack s;

    s.push(2);
    s.push(4);
    s.push(6);
    s.push(11);

    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}