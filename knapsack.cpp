#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
void knapsack(int n, float weights[], float profits[], float capacity) {
    float selectedItems[n], totalProfit = 0;
    int i, remainingCapacity;
    remainingCapacity = capacity;
    for (i = 0; i < n; i++) {
        selectedItems[i] = 0.0;
    }
    for (i = 0; i < n; i++) {
        if (weights[i] > remainingCapacity)
            break;
        else {
            selectedItems[i] = 1.0;
            totalProfit += profits[i];
            remainingCapacity -= weights[i];
        }
    }
    if (i < n)
        selectedItems[i] = static_cast<float>(remainingCapacity) / weights[i];
    totalProfit += (selectedItems[i] * profits[i]);
    cout << "Maximum profit is: " << fixed << setprecision(2) << totalProfit << endl;
}

int main() {  
    int n;
    cin >> n; 
    float weights[n], profits[n], profitToWeightRatio[n], temp, capacity;
    for (int i = 0; i < n; i++) {
        cin >> weights[i] >> profits[i]; 
    }
    cin >> capacity; 
	// Calculate the profit-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        profitToWeightRatio[i] = profits[i] / weights[i]; 
    }
	// Sort items in decreasing order of profit-to-weight ratio
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (profitToWeightRatio[i] < profitToWeightRatio[j]) {
                swap(profitToWeightRatio[i], profitToWeightRatio[j]);
                swap(weights[i], weights[j]);
                swap(profits[i], profits[j]);
            }
        }
    }
    knapsack(n, weights, profits, capacity);
    return 0;
}
