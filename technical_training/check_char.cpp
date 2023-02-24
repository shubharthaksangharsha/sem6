//Author: Shubharthak Sangharasha
/*  Date: 2023-02-24 12:18:38
         Description: Check whether the given character present or not 
*/
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        char data; 
        Node* next;
        
        //Default constructuer 
        Node(){
            this -> data = '\0';
            this -> next = NULL; 
        }

        //Paramterzied Constructor 
        Node(char ch){
            this -> data = ch; 
            this -> next  = NULL;
        }
};

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

void display(Node* head){
    while(head){
        cout << head -> data << "->";
        head = head -> next;
    }
    cout << endl;
}
Node* mid(Node* head){
    Node* fast = head->next; 
    Node* slow = head; 
    while(fast && fast -> next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* merge(Node* one, Node* two){
    if(!one){
        return two; 
    }
    if(!two){
        return one; 
    }
    Node* dummy = new Node();
    Node* temp = dummy; 
    while(one && two){
        if (one -> data < two -> data){
            temp ->next = one; 
            one = one ->next;
        } else{
            temp -> next = two; 
            two = two -> next;
        }
        temp = temp -> next;
    }
    if(one){
        temp -> next = one; 
        temp = temp -> next;
    }
    if(two){
        temp -> next = two; 
        temp = temp -> next;
    }

    return dummy->next;
}
Node* mergeSort(Node* head){
    if(!head || !head->next){
        return head; 
    }
    Node* middle = mid(head);
    Node* left = head; 
    Node* right = middle->next;
    middle->next = NULL; 
    left = mergeSort(left);
    right = mergeSort(right); 
    Node* ans = merge(left, right);
    return ans;
}
void check_char(Node* head, char search){
    //edge case 
    if(!head ){
        cout << "Linked List is empty" << endl;
        return;
    }
    int i = 1;
    while(head){
        if (head->data == search){
            cout << "Yes, character '" << head->data << "' exists at position: " << i << endl;
            return;
        }
        head = head->next;
        i++;
    }
    cout << "No character exists in the list" << endl;
}
int main(){
    cout << "******************************" << endl;
    cout << "Code by Shubharthak, 20BCS6872" << endl;
    int n; 
    Node* head = NULL;
    Node* tail = NULL;
    cout << "Enter the total number of characters you want to insert: ";    
    cin >> n; 
    while(n--){
        char ch; 
        cout << "Enter the character: "; 
        cin >> ch; 
        populate(head, tail, ch);
    }
    // display(head);
    head = mergeSort(head);
    // display(head);
    char search;
    cout << "Enter the character you want to search: "; 
    cin >> search;
    check_char(head, search);
    cout << "******************************" << endl;
    return 0;
}