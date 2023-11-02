#include <iostream>
#include <string>
using namespace std;
void findLongestPalindromicString(string text) {
    int N = text.length();
    if (N == 0)
        return;
    N = 2 * N + 1; // Position count
    int L[N + 1]; // LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1; // centerPosition
    int R = 2; // centerRightPosition
    int i = 0; // currentRightPosition
    int iMirror; // currentLeftPosition
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
    int diff = -1;
    for (i = 2; i < N; i++) {
        // get currentLeftPosition iMirror for currentRightPosition i
        iMirror = 2 * C - i;
        L[i] = 0;
        diff = R - i;
        // If currentRightPosition i is within centerRightPosition R
        if (diff > 0)
            L[i] = min(L[iMirror], diff);
        // Attempt to expand palindrome centered at currentRightPosition i. Here for odd positions,
        // we compare characters and if they match then increment LPS Length by ONE. If even position,
        // we just increment LPS by ONE without any character comparison
        while (((i + L[i]) + 1 < N && (i - L[i]) > 0) &&
               (((i + L[i] + 1) % 2 == 0) ||
                (text[(i + L[i] + 1) / 2] == text[(i - L[i] - 1) / 2]))) {
            L[i]++;
        }
        if (L[i] > maxLPSLength) // Track maxLPSLength
        {
            maxLPSLength = L[i];
            maxLPSCenterPosition = i;
        }
        // If palindrome centered at currentRightPosition i expands beyond centerRightPosition R,
        // adjust centerPosition C based on the expanded palindrome.
        if (i + L[i] > R) {
            C = i;
            R = i + L[i];
        }
    }
    start = (maxLPSCenterPosition - maxLPSLength) / 2;
    end = start + maxLPSLength - 1;
    cout << "LPS of string is " << text << " : ";
    for (i = start; i <= end; i++)
        cout << text[i];
    cout << endl;
}
int main() {
    string text;
    cin >> text;
    findLongestPalindromicString(text);
    return 0;
}
