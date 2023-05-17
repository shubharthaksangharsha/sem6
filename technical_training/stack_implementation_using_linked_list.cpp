//Author: Shubharthak Sangharasha
/*  Date: 2023-02-10 12:48:10
         Description: Stack Implementation using Linked List 
*/
#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
        int data; 
        Node* next; 
        Node(){
            this -> data = 0; 
            this -> next = NULL;
        }
        Node(int data){
            this -> data = data; 
            next = NULL;
        }

};
class stack{
    Node* top = NULL;
    public:
        void push(int data){
            Node* new_node = new Node(data);
            new_node -> next = top; 
            top = new_node;
        }

        void pop(){
            if (!top){
                cout << "Stack Underflow" << endl;
                return;
            }
            cout << "Popped element: "  << top->data << endl;
            top = top -> next;
        }

        void display(){
            if (!top){
                cout << "stack is empty" << endl;
                return;
            }
            Node *temp = top;
            cout << "Stack element are: ";
            while(temp){
                cout << temp -> data << " ";
                temp = temp -> next;
            }
            cout << endl;
        }
            
};
int main(){
  
    return 0;
}

