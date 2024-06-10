#include <bits/stdc++.h>


using namespace std;

struct Node{
    int data;
    Node *next;
};

class Stack{
    struct Node* stackTop;
public:
    Stack(){
        stackTop = NULL;
    }
    void push(){
        int value;
        Node* newNode;
        cout << "\n Enter the no.. ";
        cin >> value;
        newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if(stackTop != NULL)
            newNode->next = stackTop;
        stackTop = newNode;
    }
    void pop(){
        Node* tempNode;
        if(stackTop == NULL){
            cout << "\n Empty stack";
            return;
        }
        tempNode = stackTop;
        stackTop = stackTop->next;
        cout << "\n popped element is " << tempNode->data;
        delete tempNode;
    }
    void printStack(){
        Node* currentNode = stackTop;
        cout << "\n The stack is ";
        while (currentNode != NULL){
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }
        cout << "\n";
    }
};

int main() {
    Stack s;
    int numElements;
    cout << "\n How many elements? ";
    cin >> numElements;
    for(int i = 0; i < numElements; i++)
        s.push();
    s.printStack();
    cout << "\n How many elements to pop? ";
    cin >> numElements;
    for(int i = 0; i < numElements; i++){
        s.pop();
    }
    s.printStack();
    return 0;
}
