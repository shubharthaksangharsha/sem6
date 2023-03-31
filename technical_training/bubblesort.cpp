#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(){
            this -> data = 0; 
            this -> next = NULL; 
        }
        
        Node(int data){
            this -> data = data ; 
            this -> next = NULL; 
        }
};

void bubbleSort(Node* start) {
    Node *i, *j;
    bool swapped;
    for (i = start; i != nullptr; i = i->next) {
        swapped = false;
        for (j = start; j->next != nullptr; j = j->next) {
            if (j->data > j->next->data) {
                swap(j->data, j->next->data);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void display(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void populate(Node* &head, Node* &tail, int data){
    Node* new_node = new Node(data);
    if (!head && !tail ){
        head = new_node;
        tail = new_node;
        return;
    }
    tail -> next = new_node; 
    tail = tail -> next; 
    
}
int main() {
    cout << "Bubble Sort by Shubharthak, 20BCS6872" << endl; 
    cout << "Please enter how many nodes are present in your linked list: ";
    int n; 
    cin >> n;
    Node* head = NULL; 
    Node* tail = NULL; 
    while(n--){
        cout << "Enter the data: "; 
        int n; 
        cin >> n; 
        populate(head, tail, n);
    }
    display(head);

    bubbleSort(head);

    cout << "Sorted list:\n";
    display(head);

    return 0;
}
