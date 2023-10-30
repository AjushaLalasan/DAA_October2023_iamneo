// Implement the heap sort algorithm using a max heap. 
#include <iostream>
// Function to maintain the max heap property
void maxHeapify(int arr[], int size, int i) {
 int largest = i;
 int left = 2 * i + 1;
 int right = 2 * i + 2;
 if (left < size && arr[left] > arr[largest])
 	largest = left;
 if (right < size && arr[right] > arr[largest])
 	largest = right;
 if (largest != i) {
 	std::swap(arr[i], arr[largest]);
 	maxHeapify(arr, size, largest);
 }
}
// Function to perform Heap Sort
void heapSort(int arr[], int size) {
 for (int i = size / 2 - 1; i >= 0; i--) {	// Build a max heap from the array
 	maxHeapify(arr, size, i);
 }
 for (int i = size - 1; i > 0; i--) {	// Extract elements from the heap one by one
 	std::swap(arr[0], arr[i]);	 // Move the current root (maximum) to the end of the array
 	maxHeapify(arr, i, 0);	 // Call maxHeapify on the reduced heap
 }
}
int main() {
 int size;
 std::cin >> size;
 int arr[size];
 for (int i = 0; i < size; i++) {
 	std::cin >> arr[i];
 }
 std::cout << "Original Array: ";
 for (int i = 0; i < size; i++) {
 	std::cout << arr[i] << " ";
 }
 std::cout << std::endl;
 heapSort(arr, size);	// Perform Heap Sort
 std::cout << "Sorted Array (Heap Sort): ";
 for (int i = 0; i < size; i++) {
 	std::cout << arr[i] << " ";
 }
 std::cout << std::endl;
 return 0;
}