#include <iostream>
// Merge two sorted subarrays into one sorted array
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1; // Calculate the size of the left subarray
    int n2 = r - m;     // Calculate the size of the right subarray
    // Create temporary arrays for the left and right subarrays
    int L[n1], R[n2];
    // Copy data from the original array to the left and right subarrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    // Merge the left and right subarrays back into the original array
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    // Copy any remaining elements from the left subarray
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    // Copy any remaining elements from the right subarray
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
// Recursive function to perform Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Calculate the middle index
        // Recursively sort the left and right halves of the array
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        // Merge the sorted halves back together
        merge(arr, l, m, r);
    }
}
// Utility function to print an array
void PrintArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}
int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    // Perform Merge Sort on the array
    mergeSort(arr, 0, n - 1);
    PrintArray(arr, n);
    delete[] arr;
    return 0;
}
