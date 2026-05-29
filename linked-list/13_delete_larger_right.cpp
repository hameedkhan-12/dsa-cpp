#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = nullptr;
        }
        Node(int val1, Node* next1) {
            data = val1;
            next = next1;
        }
};

Node* arrToLL(vector<int> &arr){
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

Node* reverseLL(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while( curr != nullptr){
        next = curr -> next;
        curr -> next = prev;

        prev = curr;
        curr= next;
    }
    return prev;
}

Node* removeNodes(Node* head){
    head = reverseLL(head);

    int maxi = head -> val;
    Node* temp = head;

    while(temp != nullptr && temp -> next != nullptr){
        if(temp -> next -> val < maxi){
            Node* toDelete = temp -> next;
            temp -> next = temp -> next -> next;
            delete toDelete;
        }else{
            temp = temp -> next;
            maxi = temp -> val;
        }
    }
    return reverseLL(head);
}

int main(){
    vector<int> arr = {1,2,15,4, 13,6,7,8,9};
    Node* head = arrToLL(arr);
    head = removeNodes(head);
}