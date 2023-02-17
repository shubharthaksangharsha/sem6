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
    Node* temp = head;
    while(temp){
        cout << temp -> data << "->";
        temp = temp -> next;
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


void populate(Node* &head, Node* &tail, char ch){
    Node* new_node = new Node(ch);
    if(!head && !tail){
        head = new_node;
        tail = new_node;
        return;
    }
    tail -> next = new_node;
    tail = tail -> next;
}
Node* createList(string s){
    Node* head = NULL;
    Node* tail = NULL; 
    for(int i = 0; i < s.size(); i++){
        char ch= s[i];
        populate(head, tail, ch);
    }
    return head;
}

int main(){
    cout << "By Shubharthak, 20BCS6872" << endl;
    int n;
    cout << "How many times you want to run test cases: ";
    cin >> n;
    while(n--){
        string s;
        cout << "Enter a string: ";
        cin >> s;
        Node* head = createList(s);
        bool res = check_pallindrome(head);
        if (res){
            cout << "The given list is pallindrome" << endl;
        } else{
            cout << "The given list is not pallindrome" << endl;
        }    
    }
    cout << "Thank you for using." << endl;
}
