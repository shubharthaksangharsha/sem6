#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    //default constructor
    Node(){
        this -> data = 0;
        this -> next = NULL;
    }
    //parametized constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }

    //destructor
    ~Node(){
        int value  = this -> data;
        //memory free 
        if (this -> next != NULL){
            delete next;
            this->next= NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};
Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head; 
    while(curr){
        Node* forward = curr -> next; 
        curr -> next = prev; 
        prev = curr;
        curr = forward;
    }
    return prev;
}

void show(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << endl;
}   


Node* add(Node* one, Node* two){
    one = reverse(one);
    two = reverse(two);
    Node* dummy = new Node();
    Node* temp = dummy;
    int carry = 0; 
    while(one || two || carry){
        int sum = 0;
        if (one){
            sum += one->data;
            one = one->next;
        }
        if (two){
            sum += two->data;
            two = two->next;
        }
        sum += carry;
        Node* new_node = new Node(sum%10);
        carry = sum / 10;
        temp -> next = new_node;
        temp = temp->next;
    }
    return reverse(dummy->next);
}


int main(){
    Node* one = new Node(2);
    Node* next1 = new Node(1);
    Node* next2 = new Node(5);
    one -> next = next1; 
    next1 -> next = next2; 
    Node* two = new Node(5);
    Node* next3 = new Node(9);
    Node* next4 = new Node(2);
    two ->next = next3; 
    next3 -> next = next4;
    show(one);
    show(two);
    Node* ans = add(one, two);
    show(ans);
}
