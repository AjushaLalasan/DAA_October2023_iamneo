#include <iostream>
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Choose the pivot as the first element
    int i = low;
    int j = high;
    while (i < j) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            // Swap arr[i] and arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // Swap arr[low] and arr[j] to place the pivot in its correct position
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j; // Return the index of the pivot element
}
// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the partitioning index
        int pivotIndex = partition(arr, low, high);
        // Recursively sort elements before and after the pivot
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}