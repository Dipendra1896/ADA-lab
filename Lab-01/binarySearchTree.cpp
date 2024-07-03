#include <iostream>
using namespace std;
int binarySearch(int arr[], int p, int r, int num) {
if (p <= r) {
int mid = (p + r) / 2;
if (arr[mid] == num) {
return mid;
} else if (arr[mid] > num) {
return binarySearch(arr, p, mid - 1, num);
} else {
return binarySearch(arr, mid + 1, r, num);
}
}
return -1;
}
int main() {
int arr[] = {2, 3, 4, 10, 40};
int n = 5;
int num = 10;
int result = binarySearch(arr, 0, n - 1, num);
if(result != -1) {
cout << "Element " << num << " is present at index " << result << endl;
} else {
cout << "Element " << num << " is not present in array" << endl;
}
return 0;
}