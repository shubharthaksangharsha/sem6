//Author: Shubharthak Sangharasha
/*  Date: 2023-02-28 11:37:28
         Description: Implementation of Counting Sort.
*/
#include<bits/stdc++.h>
using namespace std;

void display(const vector<int>&nums){
    for(auto const i: nums){
        cout << i << " ";
    }
    cout << endl;
}

void input(vector<int>&nums){
    for(auto &i: nums){
        cin >> i;
    }
}

void counting_sort(vector<int>&arr){
    map<int, int>mp; 
    for(auto &i: arr){
        mp[i]++;
    }
    int i = 0; 
    for(auto &it: mp){
        int num = it.first; 
        int times = it.second; 
        while(times--){
            arr[i++] = num;
        }
    }
}
int main(){
    int n; 
    cout << "Enter the total number of elements: ";
    cin >> n; 
    vector<int>arr(n);
    input(arr);
    display(arr);
    counting_sort(arr);
    display(arr);

    return 0;
}