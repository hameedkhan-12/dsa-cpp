#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }

    Node(int val1, Node* next1, Node* prev1) {
        data = val1;
        next = next1;
        prev = prev1;
    }
};

Node* arrToDLL(vector<int>& arr) {
    if(arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for(int i = 1; i < arr.size(); i++) {

        Node* newNode = new Node(arr[i], nullptr, curr);

        curr->next = newNode;
        newNode -> prev = curr;
        curr = newNode;
    }

    return head;
}

Node* findTail(Node* head){
    Node* tail = head;

    while(tail != nullptr){
        tail = tail -> next;
    }
    return tail;
}

vector<pair<int,int>> pairSumOpt(Node* head, int target) {

    vector<pair<int,int>> ds;

    Node* left = head;
    Node* right = findTail(head);

    while(left != right && left->prev != right) {

        int sum = left->data + right->data;

        if(sum == target) {
            ds.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if(sum < target) {
            left = left->next;
        }
        else {
            right = right->prev;
        }
    }

    return ds;
}
int main() {

    vector<int> arr = {1,2,3,4,5};
    Node* head = arrToDLL(arr);
     vector<pair<int,int>> ans = pairSumOpt(head, 5);

    for(auto p : ans) {
        cout << "(" << p.first << "," << p.second << ")\n";
    }

    return 0;
}