#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int data;
        Node* next;

        Node(int val){
            data = val;
            next = nullptr;
        }
        Node(int val1, Node* next1){
            data = val1;
            next = next1;
        }
};

Node* reverseLL(Node* head){
    if( head == nullptr || head -> next == nullptr) return head;
    Node* prev = nullptr;
    Node* curr = head;

    while(curr != nullptr){
        Node* front = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = front;
    }

    return prev;
}

Node* plusOne(Node* head){
    head = reverseLL(head);
    Node* temp = head;
    int carry = 1;

    while(temp != nullptr){
        int sum = temp -> data + carry;
        temp -> data = sum % 10;
        carry = sum / 10;

        if(carry == 0) break;
        if(temp -> next == nullptr && carry > 0){
            temp -> next = new Node(carry);
            carry = 0;
            break;
        }

        temp = temp -> next;
    }
    head = reverseLL(head);
    return head;
}

Node* arrToLL( vector<int> &arr){
    if(arr.size() == 0) return nullptr;

    Node* newNode = new Node(arr[0]);
    Node* head = newNode;

    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr);
        newNode -> next = temp;
        newNode = temp;
    }
    return head;
}

void printLL(Node* head){
    if(head == nullptr) return;

    Node* temp = head;
    while(temp != nullptr){
        cout<<temp -> data<< " ";
        temp = temp -> next;
    }
}

int main(){
    vector<int> arr = {9,9,9};
    Node* head = arrToLL(arr);
    head = plusOne(head);
    // head = reverseLL(head);
    printLL(head);
}