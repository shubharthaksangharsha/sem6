#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
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

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;
    Node* fourth = nullptr;

    // allocate 4 nodes in the heap
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;

    // Assign data values
    head->data = 10;
    second->data = 20;
    third->data = 5;
    fourth->data = 15;

    // Connect nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    cout << "Original list:\n";
    printList(head);

    bubbleSort(head);

    cout << "Sorted list:\n";
    printList(head);

    return 0;
}
