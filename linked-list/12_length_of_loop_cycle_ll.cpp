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

int lengthOfCycle(Node* slow, Node* fast){
   fast = fast -> next;
    int count = 1;

    while(slow != fast){
        fast = fast -> next;
        count++;
    }

    return count;
}
int lengthOfLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow -> next;
        fast = fast -> next -> next;

        if(slow == fast){
            return lengthOfCycle(slow, fast);
        }
    }
    return 0;
}
int main(){
    vector<int> arr = {1,2,15,4, 13,6,7,8,9};
    Node* head = arrToLL(arr);
    // Creating cycle
    Node* temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = head->next; // cycle

    cout << lengthOfLoop(head);
}