#include <iostream>
#include <algorithm>
using namespace std;
// Function to solve Job Sequencing problem using greedy approach
void GreedyJob(int deadlines[], int n)
{
    // Sort deadlines in descending order
    sort(deadlines, deadlines + n, greater<int>());
    bool slot[n] = {false};
    int totalProfit = 0;
    // Iterate through sorted deadlines and allocate jobs to time slots
    for (int i = 0; i < n; ++i)
    {
        // Find available slot before the deadline
        for (int j = min(n, deadlines[i]) - 1; j >= 0; --j)
        {
            if (!slot[j])
            {
                slot[j] = true;
                totalProfit += 1; // Assuming profit of each job is 1 for simplicity
                break;
            }
        }
    }
    cout << "Total Profit: " << totalProfit << endl;
}
// Example usage for Job Sequencing Problem
int main()
{
    int deadlines[] = {8, 4, 3, 2, 1};
    int n = sizeof(deadlines) / sizeof(deadlines[0]);
    GreedyJob(deadlines, n);
    return 0;
}