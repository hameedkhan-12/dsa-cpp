#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;
    Node(int val) {
        data = val;
        next = nullptr;
        back = nullptr;
    }
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }
};

Node* arrayToDll(vector<int> &arr){
    if(arr.size() == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i = 1; i<arr.size(); i++){
        Node* newNode = new Node(arr[i], nullptr, temp);
        temp -> next = newNode;
        temp = newNode;
    }
    return head;
}


Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head -> back = newHead;
    newHead -> next = head;
    head = newHead;

    return newHead;
}

Node* insertBeforeTail (Node* head, int val){
    if(head -> next == nullptr){
        return insertBeforeHead(head, val);
    }

    Node* tail = head;
    while(tail -> next != nullptr){
        tail = tail -> next;
    }
    Node* prev = tail -> back;
    Node* newNode = new Node(val,tail, prev );
    prev -> next = newNode;
    tail -> back = newNode;
    return head;
}

Node* insertBeforeKth (Node* head, int k, int val){
    if(k == 1){
        return insertBeforeHead(head, val);
    }

    Node* temp = head;
    int count = 0;
    while(temp != nullptr){
        count++;
        if(count == k) break;
        temp = temp -> next;
    }

    Node * prev = temp -> back;
    Node* newNode = new Node(val, temp, prev);

    prev -> next = newNode;
    temp -> back = newNode;

    return head;
}

void insertBeforeNode(Node* node, int val){
    Node * prev = node -> back;
    Node * newNode = new Node(val, node, prev);
    prev -> next = newNode;
    newNode -> next = node;
    
}
void print(Node* head){
    while(head != nullptr){
        cout<<head -> data <<" ";
        head = head -> next;
    }
}
int main(){
    vector<int> arr = {5,2,1,3};
    Node * head = arrayToDll(arr);
    head = insertBeforeHead(head, 10);
    // head = insertBeforeTail(head, 20);
    head = insertBeforeKth(head, 4, 29);
    insertBeforeNode(head -> next -> next, 300);
    print(head);
}