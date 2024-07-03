#include <iostream>
#include <vector>
using namespace std;
int knapsack(const vector<int> &values, const vector<int> &weights, int capacity)
{
    int n = values.size();
    // Create a 2D array to store the maximum value at each n-th item
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
    // Build the table in bottom up manner
    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (weights[i - 1] <= w)
            {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i -1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}
int main()
{
    vector<int> values = {120, 60, 120};
    vector<int> weights = {20, 30, 40};
    int capacity = 60;
    int max_value = knapsack(values, weights, capacity);
    cout << "The maximum value that can be put in a knapsack of capacity " << capacity << " is " 
    << max_value << endl;
    return 0;
}