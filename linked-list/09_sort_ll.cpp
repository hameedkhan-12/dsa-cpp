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

Node* sortLL(Node* head){

    if(head == nullptr || head -> next == nullptr) return head;

    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);

    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;

    Node* temp = head;

    while(temp != nullptr){
        if(temp -> data == 0) {
            zero -> next = temp;
            zero = zero -> next;
        }else if( temp -> data == 1){
            one -> next = temp;
            one = one -> next;
        }else {
            two -> next = temp;
            two = two -> next;
        }
        temp = temp -> next;
    }
    zero -> next = (oneHead -> next) ? oneHead -> next : twoHead -> next;
    one -> next = twoHead -> next;
    two -> next = nullptr;
    
    Node* newHead = zeroHead -> next;
    return newHead;
}

Node* arrToLL(vector<int>& arr){
    if(arr.size() == 0) return nullptr;
    Node* head = new Node(arr[0], nullptr);
    Node* temp = head;

    for(int i = 1; i<arr.size(); i++){
        Node* newNode = new Node(arr[i], nullptr);
        temp -> next = newNode;
        temp = newNode;
    }
    return head;
}

void printLL(Node* head){
    while(head != nullptr){
        cout << head -> data << " -> ";
        head = head -> next;
    }
    cout << "NULL\n";
}

int main() {
    vector<int> arr = {0,1,1,0,1,2,1,2,0,1,0,0,0,1};
    Node* head = arrToLL(arr);
    head = sortLL(head);
    printLL(head);
    return 0;
}