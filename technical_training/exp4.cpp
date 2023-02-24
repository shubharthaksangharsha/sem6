#include<bits/stdc++.h>
using namespace std; 

void find_and_replace(string &sentence, string find, string replace){
    for(int i = 0; i < sentence.size() - find.size(); i++){
        if (sentence.substr(i, find.size()) == find){
            cout << "Starting index: " <<  i << endl;
            string prev = sentence.substr(0, i); 
            string next  = sentence.substr(i+find.size(), sentence.size() - prev.size() - find.size()); 
            string res = prev + replace + next; 
            sentence = res; 
        }
    }
     
}

int main() {
    string sentence = "Hi, I am shubharthak and I am current studying in Chandigarh University";
    cout << sentence << endl;
    string find, replace;
    cout << "Enter the word you want to find: ";
    cin >> find;
    cout << "Enter the word you want to replace: ";
    cin >> replace;
    find_and_replace(sentence, find, replace);
    cout << "After changes:-" << endl;
    cout << sentence << endl;
    return 0;
}

