#include <iostream>
#include <algorithm>
using namespace std;
// Structure for items in Knapsack problem
struct Item
{
    int weight;
    int value;
};
// Function to solve Knapsack problem using greedy approach
int GreedyKnapsack(Item items[], int n, int capacity)
{
    // Sort items based on value-to-weight ratio in descending order
    sort(items, items + n, [](Item a, Item b)
         { return (a.value / (double)a.weight) > (b.value / (double)b.weight); });
    int totalValue = 0;
    int currentWeight = 0;
    // Iterate through sorted items and fill the knapsack
    for (int i = 0; i < n; ++i)
    {
        if (currentWeight + items[i].weight <= capacity)
        {
            totalValue += items[i].value;
            currentWeight += items[i].weight;
        }
    }
    return totalValue;
}
// Example usage for Knapsack Problem
int main()
{
    Item items[] = {{30, 90}, {40, 160}, {50, 150}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 70;
    cout << "Maximum value in Knapsack: " << GreedyKnapsack(items, n, capacity) << endl;
    return 0;
}