#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = nullptr;
        }
};

Node* insertAtHead(Node * head, int val){
    Node* newNode = new Node(val);
    newNode -> next = head;
    head = newNode;

    return head;
}

Node* insertAtTail(Node*head, int val){
    Node * newNode = new Node(val);
    if(head == nullptr){
        return newNode;
    }

    Node* temp = head;
    while(temp -> next != nullptr){
        temp = temp -> next;
    }

    temp->next = newNode;
    return head;
}
 
void printLL(Node* head){
    while(head != nullptr){
        cout << head-> data<< " -> ";
        head = head -> next;
    }
    cout << "null\n";
}

Node* insertAtK(Node* head, int k, int val){
    if(k<=0){
        return head;
    }
    if(k == 1){
        Node * newNode = new Node(val);
        newNode -> next = head;

        return newNode;
    }

    Node* temp = head;
    int count = 1;

    while(temp != nullptr && count < k-1){
        temp = temp -> next;
        count++;
    }

    if(temp == nullptr){
        return head;
    }

    Node * newNode = new Node(val);

    newNode -> next = temp -> next;
    temp -> next = newNode;

    return head;
}

Node* insertBeforeValue(Node* head,int target, int val){
    Node* newNode = new Node(val);

    if(head == nullptr){
        return newNode;
    }

    if(head -> data == target){
        newNode ->next = head;

        return newNode;
    }

    Node* temp = head;

    while(temp -> next != nullptr && temp -> next->data != target){
        temp = temp -> next;
    }

    if(temp ->next == nullptr){
        delete newNode;
        return head;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;

    return head;
}
Node* insertAfterValue(Node* head, int target, int val){

    Node* newNode = new Node(val);

    if(head == nullptr){
        return newNode;
    }

    Node* temp = head;

    while(temp != nullptr && temp->data != target){

        temp = temp->next;
    }

    if(temp == nullptr){

        delete newNode;

        return head;
    }

    // Connect new node
    newNode->next = temp->next;

    temp->next = newNode;

    return head;
}
int main(){
    Node* head = nullptr;

    head = insertAtHead(head, 10);
    head = insertAtHead(head, 1);
    // head = insertAtHead(head, 2);
    // head = insertAtHead(head, 6);
    // // head = insertAtHead(head, 3);
    // head = insertAtTail(head, 122);
    // head = insertAtK(head, 5, 100);
    // head = insertBeforeValue(head, 100, 200);

    printLL(head);
}