#include <iostream>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

// void insertAtTail(Node* &head, Node* &tail, int val){

//     Node* newNode = new Node(val);

//     // Empty list
//     if(head == nullptr){
//         head = newNode;
//         tail = newNode;
//         return;
//     }

//     // Attach at tail
//     tail->next = newNode;

//     // Move tail forward
//     tail = newNode;
// }

Node* createLL(int arr[], int index, int size){
    if(index == size) return nullptr;

    Node* newNode = new Node(arr[index]);
    newNode -> next = createLL(arr, index+1, size);

    return newNode;
}
void printLL(Node* head){

    while(head != nullptr){
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

 Node* convertArrayToLL(vector <int> &arr){
    if(arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i<arr.size(); i++){
        Node* newNode = new Node(arr[i]);
        mover -> next = newNode;
        mover = newNode;
    }

    return head;
 }

Node* removeHead (Node* head){
    if(head == nullptr) return nullptr;

    Node* temp = head;
    head = head -> next;

    delete temp;

    return head;
}

Node* removeTail(Node* head){
    if(head == nullptr || head -> next == nullptr) return nullptr;

    Node*temp = head;
    while(temp -> next -> next != nullptr){
        temp = temp->next;
    }
    delete temp -> next;
    temp->next = nullptr;

    return head;
}

Node* removeK(Node* head, int k){
    if(head == nullptr) return nullptr;
    if(k == 1){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    Node* temp = head;
    int count = 1;
    while(temp != nullptr && count < k -1){
        temp = temp -> next;
        count++;
    }

    if(temp == nullptr || temp -> next == nullptr) return head;

    Node* toDelete = temp -> next;
    temp -> next = temp -> next -> next;

    delete toDelete;
    return head;
}

Node* removeValue (Node* head, int val){
    if(head == nullptr) return nullptr;

    if(head -> data == val){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }

    Node* temp = head;
    while(temp -> next != nullptr && temp -> next -> data != val){
        temp = temp -> next;
    }

    if(temp -> next == nullptr) return head;

    Node* toDelete = temp -> next;
    temp -> next = temp -> next -> next;

    delete toDelete;
    return head;
}

int main(){

    // Node* head = nullptr;
    // Node* tail = nullptr;

     vector <int> arr = {10,20,3,4,5};
    // head = createLL(arr, 0, 5);
    Node* head = convertArrayToLL(arr);
    // head = removeHead(head);
    // head = removeTail(head);
    // head = removeK(head,3);
    head = removeValue(head, 10);
    printLL(head);

}