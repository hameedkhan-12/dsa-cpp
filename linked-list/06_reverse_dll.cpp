#include <iostream>
#include <vector>

using namespace std;
class Node {
    public:
        int data;
        Node* next;
        Node* prev;
    
    Node (int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
    
    Node (int data1, Node* next1, Node* prev1){
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node* reverseDLL(Node* head) {
    if (head == nullptr || head -> next == nullptr){
        return head;
    }

    Node* curr =head;
    Node* last = nullptr;

    while(curr != nullptr){
        last = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = last;

        curr = curr -> prev;
    }

    if(last != nullptr){
        head = last ->prev;
    }
    return head;
}

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

void print(Node* head){
    while(head != nullptr){
        cout<<head -> data <<" ";
        head = head -> next;
    }
}

int main(){
    vector<int> arr = {5,2,1,3};
    Node * head = arrayToDll(arr);
    head = reverseDLL(head);
    print(head);
}