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
 
void printLL(Node* head){
    while(head != nullptr){
        cout << head-> data<< " -> ";
        head = head -> next;
    }
    cout << "null\n";
}
int main(){
    Node* head = nullptr;

    head = insertAtHead(head, 10);
    head = insertAtHead(head, 1);
    head = insertAtHead(head, 2);
    // head = insertAtHead(head, 3);

    printLL(head);
}