#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
void mergeSort(vector<int>& arr, int low, int high);
void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);
void heapSort(vector<int>& arr, int n);
void heapify(vector<int>& arr, int n, int i);
void printArray(vector<int>& arr);

// Main function
int main() {
    int n, choice;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Enter your choice of sorting algorithm:\n";
    cout << "1. Merge Sort\n2. Quick Sort\n3. Heap Sort\n";
    cin >> choice;

    switch(choice) {
        case 1: 
            mergeSort(arr, 0, n-1);
            break;
        case 2: 
            quickSort(arr, 0, n-1);
            break;
        case 3:
            heapSort(arr, n);
            break;
        default:
            cout << "Invalid choice!\n";
            return 0;
    }

    cout << "Sorted array:\n";
    printArray(arr);

    return 0;
}

// Function to perform merge sort
void mergeSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        
        // Merge the sorted sub-arrays
        vector<int> temp(high-low+1);
        int i = low, j = mid+1, k = 0;
        while(i <= mid && j <= high) {
            if(arr[i] <= arr[j]) {
                temp[k] = arr[i];
                i++;
            } else {
                temp[k] = arr[j];
                j++;
            }
            k++;
        }
        while(i <= mid) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        while(j <= high) {
            temp[k] = arr[j];
            j++;
            k++;
        }
        for(int p=0; p<k; p++) {
            arr[low+p] = temp[p];
        }
    }
}

// Function to perform quick sort
void quickSort(vector<int>& arr, int low, int high) {
    if(low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high);
    }
}

// Function to perform partition operation in quick sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j=low; j<high; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

// Function to perform heap sort
void heapSort(vector<int>& arr, int n) {
    // Build heap
    for(int i=n/2-1; i>=0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one from
for(int i=n-1; i>=0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
}
}
// Function to heapify a subtree rooted at node i
void heapify(vector<int>& arr, int n, int i) {
int largest = i; // Initialize largest as root
int l = 2*i + 1; // Left child
int r = 2*i + 2; // Right child

// If left child is larger than root
if(l < n && arr[l] > arr[largest]) {
    largest = l;
}

// If right child is larger than largest so far
if(r < n && arr[r] > arr[largest]) {
    largest = r;
}

// If largest is not root
if(largest != i) {
    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
}
}

// Function to print the elements of an array
void printArray(vector<int>& arr) {
for(int i=0; i<arr.size(); i++) {
cout << arr[i] << " ";
}
cout << endl;
}

// Enter the number of elements: 7
// Enter the elements:
// 12
// 23
// 45
// 6
// 73  
// 56
// 87
// Enter your choice of sorting algorithm:
// 1. Merge Sort
// 2. Quick Sort
// 3. Heap Sort
// 1
// Sorted array:
// 6 12 23 45 56 73 87