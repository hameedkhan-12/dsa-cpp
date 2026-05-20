#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Node {
    public:
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = nullptr;
        }
        Node(int data1, Node* next1) {
            data = data1;
            next = next1;
        }
};

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

Node* arrayToLL(vector<int> &arr){
    if(arr.size() == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* tail = head;

    for(int i =1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr);
        tail -> next = temp;
        tail = temp;
    }

    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp -> data << " -> ";
        temp = temp -> next;
    }
    cout <<nullptr << endl;
}

int main(){
        vector<int> arr = { 1,2,4,6,8,9};
        Node* head = arrayToLL(arr);
        head = reverseLL(head);
        printLL(head);
}