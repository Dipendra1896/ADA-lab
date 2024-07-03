#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
    int temp[10];
    int i = l;
    int j = m + 1;
    int k = l;
    while (i <= m && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++, k++;
        }
    }

    while (i <= m)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= r)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int x = l; x <= r; x++)
    {
        arr[x] = temp[x];
    }
}
void mergesort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(arr, l, m);
        mergesort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main()
{
    int arr[10], n;
    cout << "\nEnter the size of the array: ";
    cin >> n;
    cout << "\nEnter the required elements (n) of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "\nBefore Sorting, the elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] <<endl;
    }
    mergesort(arr, 0, n - 1);
    cout << endl
         << "\nAfter Sorting, the elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "<<endl;
    }
}