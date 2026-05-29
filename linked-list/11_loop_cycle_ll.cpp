#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int val) {
            data = val;
            next = nullptr;
        }
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
};

Node* arrayToLL(vector<int> &arr){
    if(arr.size() == 0) return nullptr;

    Node* newNode = new Node(arr[0]);
    Node* head = newNode;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr);
        newNode -> next = temp;
        newNode = temp;
    }
    return head;
}

bool isLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast -> next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast) return true;
    }
    return false;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    Node* head = arrayToLL(arr);
    cout<< isLoop(head);
}