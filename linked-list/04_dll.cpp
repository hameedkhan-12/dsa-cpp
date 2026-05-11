#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* back;

        public:
        Node(int data1, Node* next1, Node* back1){
            data = data1;
            next = next1;
            back = back1;
        }

        Node(int val){
            data = val;
            next = nullptr;
            back = nullptr;
        }
};

Node* arrayToDll(vector<int> &arr){
    if(arr.size() == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i =1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev -> next = temp;
        prev = temp;
    }

    return head;
}

Node* deleteHead(Node* head){
    if(head == NULL || head -> next == NULL) return NULL;

    Node* prev = head;
    head = head -> next;

    head-> back = nullptr;
    prev-> next = nullptr;

    delete prev;
    return head;
}

Node * deleteTail(Node* head){
    if(head == nullptr || head -> next == nullptr) return nullptr;

    Node* tail = head;
    while(tail -> next != nullptr){
        tail = tail -> next;
    }

    Node* prevOfTail = tail -> back;
    tail -> next = nullptr;
    tail -> back = nullptr;
    prevOfTail -> next = nullptr;
    delete tail;
    return head;
}

Node* deleteAtKth(Node* head,int k){
    if(head == nullptr) return nullptr;
    Node * temp = head;
    int count = 0;
    while(temp !=nullptr){
        count++;
        if(count == k) break;
        temp = temp -> next;
    }
    Node* prev = temp -> back;
    Node* front = temp -> next;
    if(prev == nullptr && front== nullptr){
        return nullptr;
    }
    else if(prev == nullptr){
        deleteHead(head);
        return nullptr;
    }else if(front == nullptr){
        deleteTail(head);
        return head;
    }
    prev -> next = front;
    front -> back = prev;
    temp -> next = nullptr;
    temp -> back = nullptr;

    delete temp;
    return head;
}

void removeNode(Node* temp){
    Node* prev = temp -> back;
    Node* front = temp -> next;

    if(front == nullptr){
        prev -> next = nullptr;
        temp -> back = nullptr;
        free(temp);
        return;
    }
    prev -> next = front;
    front -> back = prev;

    temp -> next = temp -> back = nullptr;
    free(temp);
}
void print(Node* head){
    while(head != nullptr){
        cout<< head -> data << " ";
        head = head -> next;
    }
}
int main(){
    vector<int> arr = {12, 5, 8, 9};
    Node* head = arrayToDll(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = deleteAtKth(head, 3);
    removeNode(head -> next->next);
    print(head);

}