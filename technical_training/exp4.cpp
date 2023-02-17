#include<bits/stdc++.h>
using namespace std; 

void find_and_replace(string &sentence, string find, string replace){
    int start = 0, end = 0;
    int counter = 0;
    for(int i = 0; i < sentence.size(); i++){
        if(sentence[i] == find[0]){
            start = i;
            counter = 1;
            
        }
        if(counter == 1){
            if(sentence[i] == find[find.size() - 1]){
                end = i;
                break;
            }
        }
        
    }
    cout << "Find string at index: " << start << endl;
    sentence.replace(start, find.size(), replace );
    
    // string temp;
    // int start = 0, end = 0;
    // cout << find[0] << " " << find[find.size() - 1] << endl;
    // for(int i = 0; i < sentence.size(); i++){
    //      if (sentence[i] == find[0]){
    //          start = i;
    //      }  
    //      if (sentence[i] == find[find.size() - 1]){
    //          end = i;
    //      }
    //   }
    //   cout << "start: " << start << endl;
    //   cout << "end: " << end << endl;
    //  for(int i = start; i <= end; i++){
    //      sentence[i] = replace[i]; 
    //  }
     
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
