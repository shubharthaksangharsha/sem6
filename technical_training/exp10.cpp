//Author: Shubharthak Sangharasha
/*  Date: 2023-05-22 
         Description:
*/
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void input(vector<int>&arr){
    for(auto &i: arr){
        cin >> i;
    }
}

void display(const vector<int>arr){
    for(auto const i: arr){
        cout << i << " ";
    }
    cout << endl;
}

void reverse_using_stack(vector<int>&v){
    stack<int>st;
    for(auto &x : v){
        st.push(x);
    }
    int itr=0;

    while(st.size()){
        v[itr++] = st.top();
        st.pop();

    }

}

 
int main(){
    int n1, n2;
    cout << "Enter the size of the array1: ";
    cin >> n1;
    cout << "Enter the elements: ";
    vector<int>arr1(n1);
    input(arr1);
    cout << "Enter the size of the array2: ";
    cin >> n2;
    cout << "Enter the elements: ";
    vector<int>arr2(n2);
    input(arr2);
    reverse_using_stack(arr1);
    reverse_using_stack(arr2);
    display(arr1);
    display(arr2);
    return 0;
}