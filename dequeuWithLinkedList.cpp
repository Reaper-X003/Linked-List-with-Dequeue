#include <bits/stdc++.h>

using namespace std;

// Define node pointer
struct node {
    int data;
    node* next;
};

// Head and tail pointers
node* queueHead;
node* queueTail;

// Functions
int menu();
void enqueue(node *& queueHead, node *&queueTail, int data);
void dequeue(node *&queueHead, node *& queueTail);
void front(node *& queueHead);
bool isEmpty(node *& queueHead);
int randomNumber(int min, int max);

//Main function
int main() {
    
    node* queueHead;
    node* queueTail;
    
    queueHead = NULL;
    queueTail = NULL;
    int userChoice;
    printf("Number is %d", randomNumber(0, 10));
    do {
        userChoice = menu();
        
        switch(userChoice) {
            case 1:
                int inputData;
                cout<<"Enter value to be stored in queue: ";
                cin>>inputData;
                enqueue(queueHead, queueTail, inputData);
                break;
            case 2:
                dequeue(queueHead, queueTail);
                break;
            case 3:
                front(queueHead);
                break;
            case 4:
                printf("Not implemented");
                break;
            case 5:
                isEmpty(queueHead);
                break;
            case -1:
                userChoice = -1;
                break;
                
            default: printf("\nEnter a valid choice!!");
        }
    } while(userChoice != -1);
    
    return 0;
}

//Menu function
int menu() {
    int ch;
    printf("\nQueue Operations");
    printf("\n1.Enqueue\n2.Dequeue\n3.Front element\n4.Is Full\n5.Is Empty\n6.Exit");
    printf("\nEnter your Choice:");
    scanf("%d",&ch);
    return ch;
}

//Enqueue element in queue
void enqueue(node *& queueHead, node *&queueTail, int data) {
    if (queueHead == NULL) {
        node* newNode = new node;
        
        newNode->data = data;
        newNode->next = NULL;
        
        queueHead = newNode;
        queueTail = newNode;
        
    } else {
        node* newNode = new node;
        newNode->data = data;
        newNode->next = queueHead;
        queueHead = newNode;
    }
}

// Dequeue first element in a queue
void dequeue(node *&queueHead, node *& queueTail) {
    if (queueHead == NULL) {
        printf("\nThe queue is empty.");
        
    } else if (queueHead == queueTail) {
        // Case when there is only 1 element in the queue
        printf("The value %d was dequeued", queueHead->data);
        delete queueHead;
        queueHead = NULL;
        queueTail = NULL;
        
    } else {
        node* tempNode = new node;
        tempNode = queueTail;
        if(queueTail->next == NULL) {
            queueTail = queueHead;
        } else {
            queueTail = queueTail->next;
        }
        
        printf("\nThe value %d was dequeued", tempNode->data);
        delete tempNode;
    }
}

//Show front-most element in queue
void front(node *& queueHead) {
    if (queueHead == NULL) {
        printf("\nThe queue is empty");
        
    } else {
        printf("\nFront number is %d", queueHead->data);
    }
}

// Shows if the queue is empty
bool isEmpty(node *& queueHead) {
    if(queueHead == NULL) {
        printf("\nThe queue is empty");
        return true;
        
    } else {
        printf("\nThe queue is not empty");
        return false;
    }
}

int randomNumber(int min, int max) {
    static bool first = true;
    if ( first )
    {
        srand(time(NULL)); 
        first = false;
    }
    return min + rand() % (max - min);
}
