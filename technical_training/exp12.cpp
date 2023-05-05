#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight, profit;
};

int knapsack(int capacity, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            if (items[i - 1].weight <= j) {
                dp[i][j] = max(items[i - 1].profit + dp[i - 1][j - items[i - 1].weight], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int capacity;
    cout << "Enter the capacity of the sack: ";
    cin >> capacity;

    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter the weight and profit of item " << i + 1 << ": ";
        cin >> items[i].weight >> items[i].profit;
    }

    int maxProfit = knapsack(capacity, items);

    cout << "The maximum profit that can be earned is: " << maxProfit << endl;

    return 0;
}
