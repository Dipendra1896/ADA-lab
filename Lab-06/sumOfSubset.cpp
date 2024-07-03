#include <iostream>
#include <vector>
using namespace std;
void subsetSum(vector<int> &set, int target, vector<int> &current, int index, int currentSum)
{
    if (currentSum == target)
    {
        cout << "Subset found: ";
        cout << "{ ";
        for (int num : current)
        {
            cout << num << " ";
        }
        cout << " }";
        cout << endl;
        return;
    }
    // Backtracking step: Explore the remaining elements
    for (int i = index; i < set.size(); ++i)
    {
        // Add current element to the subset
        current.push_back(set[i]);
        currentSum += set[i];
        // Recursively search with updated subset and sum
        subsetSum(set, target, current, i + 1, currentSum);
        // Backtrack: Remove current element from the subset and adjust the sum
        current.pop_back();
        currentSum -= set[i];
    }
}
// Main function
int main()
{
    vector<int> set = {2, 7, 5, 8, 4, 6};
    int target = 12;
    vector<int> current; // To store current subset
    int index = 0;       // Starting index for recursion
    int currentSum = 0;  // Current sum of elements in subset

    cout << "Subsets with sum " << target << ":" << endl;
    subsetSum(set, target, current, index, currentSum);
    return 0;
}