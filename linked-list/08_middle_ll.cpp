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
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
};

Node* middleLL(Node *head){
    Node* middle = head;
    Node* temp = head;

    while(temp != nullptr && temp -> next != nullptr){
        middle = middle -> next;
        temp = temp -> next -> next;
    }

    return middle;
}

Node * arrayToLL(vector<int> &arr){
    if(arr.size() == 0) return nullptr;
    Node* head = new Node(arr[0], nullptr);

    Node* temp = head;
    for(int i = 1; i<arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        temp -> next = newNode;
        temp = newNode;
    }
    return head;
}

void printLL(Node * head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp -> data<< " ";
        temp = temp -> next;
    }
}

int main(){
    vector<int> arr = {2,3,4,5,7};
    Node * head = arrayToLL(arr);
    head = middleLL(head);
    printLL(head);
}