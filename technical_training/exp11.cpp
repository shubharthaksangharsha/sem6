#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight, profit;
};

bool cmp(Item a, Item b) {
    double r1 = (double) a.profit / a.weight;
    double r2 = (double) b.profit / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);

    double totalProfit = 0.0;
    int n = items.size();

    for (int i = 0; i < n; i++) {
        if (capacity == 0) {
            return totalProfit;
        }

        if (items[i].weight <= capacity) {
            totalProfit += items[i].profit;
            capacity -= items[i].weight;
        } else {
            totalProfit += ((double) items[i].profit / items[i].weight) * capacity;
            capacity = 0;
        }
    }

    return totalProfit;
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

    double maxProfit = fractionalKnapsack(capacity, items);

    cout << "The maximum profit that can be earned is: " << maxProfit << endl;

    return 0;
}
