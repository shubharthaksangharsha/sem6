//Author: Shubharthak Sangharasha
/*  Date: 2023-02-10 12:25:51
         Description: Implementation of stack using array and linked list 
*/
#include<iostream>
using namespace std;

template<typename T>
class stack{
    int *arr;
    int top; 
    int size;
    public:
    stack(int size){
        arr = new int[size];
        top = -1;
        this -> size = size;
    }
    void push(T data){
        if(top >= size){
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = data;
    }
    void pop(){
        if(top < 0){
            cout << "Stack Underflow" << endl;
            return;
        }
        top--;
    }
    T show(){
        if (top < 0){
            return -1;
        }
        return arr[top];
    }

    void display(){
        for(int i = 0; i <= top; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

void callMenu(stack<int> &s, int choice){
    switch (choice){
        case 1: 
            int val;
            cout << "Enter the value of you want to push in stack: ";
            cin >> val;
            s.push(val);
        break;

        case 2: 
            s.pop();
        break;

        case 3: 
            cout <<"Top element: " << s.show() << endl;
        break;

        case 4:
            s.display();
        break;


    }
}
int main(){
    int size, choice;
    cout <<"Enter size of the stack: ";
    cin >> size;
    stack<int> s(size);
    while (true){
        cout << "1: Push element into stack" << endl;
        cout << "2. Pop element from stack"  << endl;
        cout << "3: Display top element of stack" << endl;
        cout << "4: Display all element of stack" << endl;
        cout << "5: Exit" << endl;
        cin >> choice;
        if(choice == 5){
            break;
        }
        callMenu(s, choice);
    }   

    return 0;
}