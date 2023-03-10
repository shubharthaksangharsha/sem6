//stable counting sort 
#include <bits/stdc++.h>
using namespace std;

void display(const vector<int>& nums){
    for(auto const i: nums){
        cout << i << " ";
    }
    cout << endl;
}

void input(vector<int>& nums){
    for(auto &i: nums){
        cin >> i;
    }
}

void counting_sort(vector<int>& arr) {
    map<int, vector<int>> mp;
    for (auto num : arr) {
        if (mp.find(num) == mp.end()) {
            mp[num] = vector<int>{};
        }
        mp[num].push_back(num);
    }
    int i = 0;
    for (auto it : mp) {
        for (auto num : it.second) {
            arr[i++] = num;
        }
    }
}

int main(){
    int n;
    cout << "Enter the total number of elements: ";
    cin >> n;
    vector<int> arr(n);
    input(arr);
    counting_sort(arr);
    display(arr);
    return 0;
}
