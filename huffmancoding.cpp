#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Define a struct to represent nodes in a Huffman Tree.
struct HuffmanNode {
    int data;            // Frequency of the character (used for sorting in the priority queue).
    char c;              // Character stored in the node.
    HuffmanNode* left;   // Pointer to the left child node.
    HuffmanNode* right;  // Pointer to the right child node.
};

// Define a custom comparator to be used for sorting HuffmanNode pointers in a priority queue.
struct MyComparator {
    bool operator()(HuffmanNode* x, HuffmanNode* y) {
        return x->data > y->data; // Compare nodes based on their frequencies.
    }
};

// Function to print Huffman codes for characters in the tree.
void printCode(HuffmanNode* root, string s) {
    if (!root->left && !root->right && isalpha(root->c)) {
        cout << root->c << ":" << s << endl; // Print character and its corresponding Huffman code.
        return;
    }
    // Recursively traverse left and right branches of the tree, appending '0' and '1' to the code string.
    printCode(root->left, s + "0");
    printCode(root->right, s + "1");
}

// Function to build a Huffman Tree and print Huffman codes for characters.
void buildHuffmanTreeAndPrintCodes(vector<char>& charArray, vector<int>& charfreq) {
    int n = charArray.size();
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, MyComparator> q; // Priority queue to store nodes.

    // Create leaf nodes for each character and their corresponding frequencies.
    for (int i = 0; i < n; i++) {
        HuffmanNode* hn = new HuffmanNode();
        hn->c = charArray[i];
        hn->data = charfreq[i];
        hn->left = nullptr;
        hn->right = nullptr;
        q.push(hn); // Add the node to the priority queue.
    }

    HuffmanNode* root = nullptr;
    while (q.size() > 1) {
        HuffmanNode* x = q.top();
        q.pop();
        HuffmanNode* y = q.top();
        q.pop();

        // Create a new internal node with a frequency equal to the sum of its children's frequencies.
        HuffmanNode* f = new HuffmanNode();
        f->data = x->data + y->data;
        f->c = '-';
        f->left = x;
        f->right = y;
        root = f; // Update the root of the Huffman Tree.
        q.push(f); // Add the new node back to the priority queue.
    }

    // Call the printCode function to print Huffman codes for characters in the Huffman Tree.
    printCode(root, "");
}

int main() {
    int n;
    cin >> n;
    vector<char> charArray(n);
    vector<int> charfreq(n);

    // Read character and frequency data from input.
    for (int i = 0; i < n; i++) {
        cin >> charArray[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> charfreq[i];
    }

    // Build the Huffman Tree and print Huffman codes.
    buildHuffmanTreeAndPrintCodes(charArray, charfreq);
    return 0;
}
