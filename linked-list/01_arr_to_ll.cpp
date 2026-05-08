#include <iostream>
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
};

// Function to convert array → linked list
Node* arrayToLL(vector<int>& arr) {
    if (arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);

    cout << "Head created:\n";
    cout << "Address of head node: " << head << endl;
    cout << "Data at head: " << head->data << endl;
    cout << "Next of head: " << head->next << endl;
    cout << "----------------------\n";

    Node* current = head;

    cout << "Current set to head node:\n";
    cout << "Address: " << current << endl;
    cout << "Data: " << current->data << endl;
    cout << "Next: " << current->next << endl;
    cout << "----------------------\n";

    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);

        cout << "Creating new node:\n";
        cout << "Address: " << newNode << endl;
        cout << "Data: " << newNode->data << endl;
        cout << "Next: " << newNode->next << endl;
        cout << "----------------------\n";

        current->next = newNode;

        cout << "Link formed:\n";
        cout << "Node with data " << current->data 
             << " now points to address " << current->next << endl;

        current = current->next;

        cout << "Pointer moved. Current now at address: " << current << endl;
        cout << "----------------------\n";
    }

    return head;
}

// Function to print full linked list
void printLL(Node* head) {
    Node* temp = head;

    cout << "\nTraversing Linked List:\n";

    while (temp != nullptr) {
        cout << "Node Address: " << temp 
             << " | Data: " << temp->data 
             << " | Next: " << temp->next << endl;

        temp = temp->next;
    }
}

int lengthOfLL (Node* head){
    int count = 0;
    Node * temp = head;

    while(temp){
        // cout<< temp->data<< " ";
        temp = temp -> next;
        count++;
    }
    return count;
}

int checkIfPresent(Node* head, int val){
    Node * temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    vector<int> arr = {1, 2, 3,4};

    Node* head = arrayToLL(arr);

    printLL(head);
    cout << checkIfPresent(head,2);

    return 0;
}