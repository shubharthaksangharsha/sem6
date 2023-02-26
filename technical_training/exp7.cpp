//Author: Shubharthak Sangharasha
/*  Date: 2023-02-05 18:20:40
         Description: Implementation of Tries Data Structure.
*/
#include<bits/stdc++.h>
using namespace std;
class TrieNode{
    public:
        char data; 
        TrieNode* children[26];
        bool isTerminal;
        TrieNode(char d){
            this->data = d; 
            for(int i = 0; i < 26; i++){
                children[i] = NULL;
            }
            this -> isTerminal = false;
        }
};
class Trie {
private:
    TrieNode* root;
    void insertUtil(TrieNode* root, string word){
        //base case (if reached end)
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }
        //get index 
        int index = word[0] - 'a';
        TrieNode* child; 
        //if present
        if(root->children[index] != NULL){
            child = root->children[index];
        } else{
            //not present 
            child = new TrieNode(word[0]); 
            root->children[index] = child;
        }
        //Recursion
        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode* root, string word){
        //base case 
        if(word.length() == 0){
            return root->isTerminal;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        } else{
            return false;
        }
        return searchUtil(child, word.substr(1));

    }

public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        insertUtil(root, word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchUtil(root, word);
    }   
};

int main(){
    int t; 
    cout << "Enter how many times you want to run test cases: ";
    cin >> t;
    while(t--){
        Trie trie;
        cout << "Enter how many word you want to insert: ";
        int n; 
        cin >> n;
        for(int i = 0; i < n; i++){
            string temp;
            cout << "Enter the string you want to insert: ";
            cin >> temp;
            trie.insert(temp);
        }
        string search;
        cout << "Enter the word you want to search: ";
        cin >> search;
        bool ans =  trie.search(search);
        if(ans){
            cout << "Word present" << endl;
        } else{
            cout << "Word not present " << endl;
        }
    }
    
    return 0;
}
