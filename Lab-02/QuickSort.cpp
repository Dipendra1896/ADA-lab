#include <iostream>
using namespace std;
int Partition(int arr[], int p, int q) {
int pivot = arr[q];
int i = p - 1;
for (int j = p; j < q; j++) {
if (arr[j] <= pivot) {
i++;
swap(arr[i], arr[j]);
}
}
swap(arr[i + 1], arr[q]);
return i + 1;
}
void QuickSort(int arr[], int p, int q) {
if (p < q) {
int j = Partition(arr, p, q);
QuickSort(arr, p, j - 1);
QuickSort(arr, j + 1, q);
}
}
int main() {
int arr[10], n;
cout << "\nEnter the size of the array: ";
cin >> n;
cout << "\nEnter the required elements (n) of the array: ";
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
cout << "\nBefore Sorting, the elements are: ";
for (int i = 0; i < n; i++) {

cout << arr[i] << " ";
}
QuickSort(arr, 0, n - 1);
cout << endl << "\nAfter Sorting, the elements are: ";
for (int i = 0; i < n; i++) {
cout << arr[i] << " ";
}
return 0;
}