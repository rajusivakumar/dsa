#include<iostream>
#include<algorithm>
using namespace std;

// Define a struct to represent an item in the knapsack
struct Item {
    int value;
    int weight;
};

// Define a comparison function to sort items based on value-to-weight ratios
bool compare(Item a, Item b) {
    double ratio1 = (double)a.value / (double)a.weight;
    double ratio2 = (double)b.value / (double)b.weight;
    return ratio1 > ratio2; // sort in descending order
}

// Define the function to solve the fractional knapsack problem
double fractionalKnapsack(int W, Item arr[], int n) {
    // Sort the items in descending order based on value-to-weight ratios
    sort(arr, arr + n, compare);

    // Initialize the current weight and final value of items in the knapsack
    double currentWeight = 0.0;
    double finalValue = 0.0;

    // Iterate through the items and add them to the knapsack as long as their weight does not exceed the remaining capacity
    for (int i = 0; i < n; i++) {
        if (currentWeight + arr[i].weight <= W) {
            // Add the entire item to the knapsack if its weight does not exceed the remaining capacity
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else {
            // Add a fraction of the item to the knapsack if its weight exceeds the remaining capacity
            int remainingWeight = W - currentWeight;
            finalValue += arr[i].value * ((double)remainingWeight / (double)arr[i].weight);
            break; // exit the loop
        }
    }

    // Return the final value of items in the knapsack
    return finalValue;
}

// Main function to take input from the user and call the fractionalKnapsack function
int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum weight of knapsack: ";
    cin >> W;

    // Create an array of items and take input from the user for each item's value and weight
    Item arr[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter the value and weight of item " << i+1 << ": ";
        cin >> arr[i].value >> arr[i].weight;
    }

    // Call the fractionalKnapsack function to calculate the maximum value of items that can be put in the knapsack
    double maxVal = fractionalKnapsack(W, arr, n);
    cout << "The maximum value of items that can be put in the knapsack is: " << maxVal << endl;

    return 0;
}
// Enter the number of items: 5
// Enter the maximum weight of knapsack: 10
// Enter the value and weight of item 1: 60 10
// Enter the value and weight of item 2: 100 20
// Enter the value and weight of item 3: 120 30
// Enter the value and weight of item 4: 200 40
// Enter the value and weight of item 5: 240 50
// The maximum value of items that can be put in the knapsack is: 460