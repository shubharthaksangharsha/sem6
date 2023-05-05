//By Shubharthak
/*
    Date: 5th May 2023
        Description: Implementation of stack using 2 queues. 
*/

#include<bits/stdc++.h>
using namespace std; 

class Stack{
    private:
        queue<int>q1, q2;
        int size; 
    public:
        //default construcotr 
        Stack(){
            this -> size = 5; 
        }
        //parametized constructor 
        Stack(int size){
            this -> size = size; 
        }
        void push(int value){
            if(q1.size() == size){
                cout << "Stack Overflow!" << endl;
                return;
            }
            q1.push(value);
        }
        void pop(){
            if(q1.empty()){
                cout << "Stack Underflow" << endl;
                return;
            }
            while(q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }
            cout << "Popped element: " << q1.front() << endl;
            q1.pop();
            swap(q1, q2);
        }
        void display() {
            if (q1.empty()) {
                cout << "Stack is empty." << endl;
                return;
            }
    
            queue<int> temp = q1;
    
            cout << "Elements of the stack: ";
    
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
    
            cout << endl;
    }
};
int main() {
    int size; 
    cout << "Enter the size of the stack: ";
    cin >> size; 
    Stack s(size);
    int option = 0;
    while(1){
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> option;
        switch(option){
            case 1:
                int data; 
                cout << "Enter element you want to push: ";
                cin >> data; 
                s.push(data);
                break;
            case 2:
                s.pop(); 
                break;
            case 3: 
                s.display(); 
                break;
            case 4:
                return 0;
            default:
                cout << "Wrong choice" << endl;
        }
    }
    return 0;
}
