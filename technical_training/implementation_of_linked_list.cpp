//Author: Shubharthak Sangharasha
/*  Date: 2023-02-15 10:32:11
         Description: Implentation of Linked List
*/

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

class SinglyLinkedList{
    public:
        Node* head = NULL;
        Node* tail = NULL;
        int count = 0;
        void insert_at_head(int data);
        void insert_at_tail(int data);
        void insert_at_end(int data);
        void insert_at_position(int pos, int data);
        void delete_node(int pos);
        void display();
        int size(){return count;}
};

void SinglyLinkedList::insert_at_head(int data){
    Node* new_node = new Node(data);
    if (!head){
        head = new_node;
        tail = head;
        count++;
        return;
    }
    new_node -> next = head;
    head = new_node;
    count++;
}

void SinglyLinkedList::insert_at_tail(int data){
    Node* new_node = new Node(data);
    tail -> next = new_node;
    tail = new_node;
    count++;
}
void SinglyLinkedList::insert_at_position(int pos, int data){
    if(pos <= 0 || pos > count){
        cerr<< "Invalid Position" << endl;
        return;
    } 
    if (pos == 1){
        insert_at_head(data);
        return;
    } 
    if (count == pos - 1){
        insert_at_tail(data);
        return;
    }
    Node* temp = head;
    Node* new_node = new Node(data);
    int cnt = 1; 
    while(cnt < pos - 1){
        temp = temp -> next;
        cnt++;
    }
    new_node ->next = temp->next;
    temp->next = new_node;
    count++;
}
/*
temp
|6| -> |2|-> |1|-> null
head
head = head->next
delete temp;
*/
void SinglyLinkedList::delete_node(int pos){
    count--;
    if (pos == 1){
        if (!head->next){
            head = NULL;
            return;
        }
        Node *temp = head;
        head = head ->next;
        temp -> next = NULL;
        delete temp;
        return;
    } 
    Node* current = head;
    Node* prev = NULL;
    int cnt = 1;
    while (cnt < pos){
        prev = current;
        current = current ->next;
        cnt++;
    }
    prev ->next = current ->next;
    current -> next = NULL;
    delete current;
}
void SinglyLinkedList::insert_at_end(int data){
    Node* new_node = new Node(data);
    Node* temp = head;
    while(temp ->next){
        temp = temp -> next;
    }
    count++;
    temp -> next = new_node;
}
void SinglyLinkedList::display(){
    Node* temp = head;
    while(temp){
        cout << temp -> data << "->";
        temp = temp -> next;
    }
    cout << endl;
}

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
    show(one);
    two = reverse(two);
    show(two);
    Node* dummy = new Node();
    Node* temp = dummy;
    int carry = 0; 
    while(one || two || carry){
        int sum = 0;
        if (one){
            sum += one->data;
        }
        if (two){
            sum += two->data;
        }
        sum += carry;
        Node* new_node = new Node(sum%10);
        carry = sum / 10;
        temp -> next = new_node;
        temp = temp->next;
        if (one){
            one = one->next;
        }
        if(two){
            two = two->next;
        }
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

