//Author: Shubharthak Sangharasha
/*  Date: 2023-02-16 23:10:06
         Description: Check whether linked list is pallindrome or not.
*/
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        char data; 
        Node* next;
        //Default Constructor
        Node(){
            this -> data = '\0';
            this -> next = NULL;
        }
        //Parametized Constructor
        Node(char data){
            this ->data = data; 
            this -> next = NULL;
        }
};

void show(Node* head){
    while(head){
        cout << head -> data << "->";
        head = head -> next;
    }
    cout << endl;
}
Node* reverse(Node* head){
    Node* prev = NULL;
    while(head){
        Node* forward = head -> next;
        head -> next  = prev;
        prev = head; 
        head = forward;
    }
    return prev;
}
Node* middle(Node* head){
    Node* fast= head -> next;
    Node* slow = head;
    while(fast && fast -> next){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return slow;
}
bool check_pallindrome(Node* head){
    //edge cases 
    if(!head || !head->next){
        return true;
    }
    Node* mid = middle(head);
    Node* head2 = reverse(mid -> next);
    mid -> next = NULL;
    while(head2){
        if (head->data != head2->data){
            return false;
        }
        head = head->next;
        head2 = head2->next;
    }
    return true;
}

int main(){
    Node* head = new Node('a');
    Node *next = new Node('b');
    Node* next2 = new Node('c');
    head -> next = next;
    next -> next = next2;
    show(head);
    bool res = check_pallindrome(head);
    if (res){
        cout << "The given list is pallindrome" << endl;
    } else{
        cout << "The given list is not pallindrome" << endl;
    }
}