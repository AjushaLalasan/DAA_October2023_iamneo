// Given an array, write a function to convert it into a valid binary min heap in-place.
#include <iostream>
// Function to maintain the min heap property for a single node
void minHeapify(int arr[], int size, int i) {
 int smallest = i;
 int left = 2 * i + 1;
 int right = 2 * i + 2;
 if (left < size && arr[left] < arr[smallest])
 	smallest = left;
 if (right < size && arr[right] < arr[smallest])
 	smallest = right;
 if (smallest != i) {
 	std::swap(arr[i], arr[smallest]);
 	minHeapify(arr, size, smallest);
 }
}
// Function to convert an array into a valid binary min heap in-place
void buildMinHeap(int arr[], int size) {
 // Start from the last non-leaf node and heapify all nodes in reverse order
 for (int i = (size / 2) - 1; i >= 0; i--) {
 minHeapify(arr, size, i);
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
 // Convert the array into a valid binary min heap
 buildMinHeap(arr, size);
 std::cout << "Min Heap: ";
 for (int i = 0; i < size; i++) {
 	std::cout << arr[i] << " ";
 }
 std::cout << std::endl;
 return 0;
}