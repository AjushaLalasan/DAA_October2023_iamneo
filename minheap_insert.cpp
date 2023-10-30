// Write a program to insert an element into a min heap and maintain the heap property.
#include <iostream>
using namespace std;
void insertIntoMinHeap(int heap[], int& size, int value) {
 // Add the new element at the end of the heap
 size++;
 int currentIndex = size - 1;
 heap[currentIndex] = value;
 // Maintain the min heap property by comparing with parent nodes
 while (currentIndex > 0 && heap[currentIndex] < heap[(currentIndex - 1) / 2]) {
 	swap(heap[currentIndex], heap[(currentIndex - 1) / 2]);
 	currentIndex = (currentIndex - 1) / 2;
 }
}
int main() {
 int maxHeapSize;
 cin >> maxHeapSize;
 int minHeap[maxHeapSize]; // Create a min heap with the specified maximum size
 int heapSize = 0;
 int element;
 while (heapSize < maxHeapSize) {
 	cin >> element;
 	if (element == -1) {
 		break;
 	}
 	insertIntoMinHeap(minHeap, heapSize, element);
 }
 cout << "Min Heap: ";
 for (int i = 0; i < heapSize; i++) {
 	cout << minHeap[i] << " ";
 }
 cout << endl;
 return 0;
}
