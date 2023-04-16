#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];
    cout << "Enter the array elements in sorted order: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target element to search: ";
    cin >> target;

    int result = binarySearch(arr, 0, size - 1, target);
    if (result == -1) {
        cout << "Target element is not present in the array." << endl;
    } else {
        cout << "Target element is present at index " << result << " in the array." << endl;
    }
    return 0;
}
 //  Enter the size of the array: 5
// Enter the array elements in sorted order: 10 12 16 18 23 
// Enter the target element to search: 18
// Target element is present at index 3 in the array.
// 