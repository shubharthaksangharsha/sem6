//Author: Shubharthak Sangharasha
/*  Date: 2023-02-24 13:37:26
         Description: Get the common roll number in all the three list 
*/
#include<bits/stdc++.h>
using namespace std;
bool isPresent(vector<pair<int, string>>&v, int k){
    int n = v.size(); 
    int l = 0, r = n -1;
    while(l <= r){
        int m = (l + r) / 2; 
        if(v[m].first == k){
            return true;
        } else if(v[m].first < k){
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return false;
}
int main(){
    /*
    1st list = [{6, shubharthak}, {2, aviral}, {3, mohit}, {4, rohit}]
    2nd list = [{1, BCA}, {2, CSE}, {3, BE}, {4, LLB}]
    3rd list = [{6, 8.2}, {2, 3.2}, {3, 8.2}, {4, 9.2}]
    */
    int n, n1, n2, n3; 
    cout << "Enter the total roll number present in list 1: "; 
    cin >> n1; 
    
    vector<pair<int, string>>v1(n1);
    for(int i = 0; i< v1.size(); i++){
        cout << "Enter the roll number: ";
        cin >> v1[i].first;
        cout << "Enter the name: ";
        cin >> v1[i].second;
    }
    cout << "Enter the total roll number present in list 2: ";
    cin >> n2;
    vector<pair<int, string>>v2(n2);
    for(int i = 0; i< v2.size(); i++){
        cout << "Enter the roll number: ";
        cin >> v2[i].first;
        cout << "Enter the Course Name: ";
        cin >> v2[i].second;
    }
    cout << "Enter the total roll number present in list 3: ";
    cin >> n3; 
    vector<pair<int, string>>v3(n3);
    for(int i = 0; i< v3.size(); i++){
        cout << "Enter the roll number: ";
        cin >> v3[i].first;
        cout << "Enter the CGPA: ";
        cin >> v3[i].second;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    cout << "List1: ";
    for(auto const i : v1){
            cout << "[" << i.first << ", " << i.second << "], ";
        }
    cout << endl;
    cout << "List2: ";
    for(auto const i : v2){
            cout << "[" << i.first << ", " << i.second << "], ";
        }
    cout << endl;
    cout << "List3: ";
    for(auto const i : v3){
            cout << "[" << i.first << ", " << i.second << "], ";
        }
    cout << endl;
    n1 = v1.size(), n2 = v2.size(), n3 = v3.size();
    n = min(n1, min(n2, n3));
    vector<int>ans; 
    if (n1 == n){
        for(int i = 0; i < n; i++){
            if(isPresent(v2, v1[i].first) && isPresent(v3, v1[i].first)){
                ans.push_back(v1[i].first);
            }
        }
    } else if(n2 == n){
        for(int i = 0; i < n; i++){
            if (isPresent(v1, v2[i].first) && isPresent(v3, v2[i].first)){
                ans.push_back(v2[i].first);
            }
        }
    } else{
        for(int i = 0; i < n; i++){
            if(isPresent(v2, v3[i].first) && isPresent(v1, v3[i].first)){
                ans.push_back(v3[i].first);
            }
        }
    }
    cout << "Common Roll Numbers: ";
    if(ans.size() == 0){
        cout << "No Roll Numbers are common" << endl;
    } else {
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
    }
    cout << endl;
    return 0;
}
