#include <iostream>
#include <string>
using namespace std;
const int d = 256;
void rabinKarp(string pat, string txt, int q) {
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
    // Calculate h: h = (d^(M-1)) % q
    for (i = 0; i < M - 1; i++) {
        h = (h * d) % q;
    }
    bool found = false;
    // Calculate the initial hash values for pattern and the first window of text
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }
    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {
        // Check if the hash values match
        if (p == t) {
            // Check for characters one by one
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }
            if (j == M) {
                found = true;
                cout << "Found at " << i << endl;
            }
        }
        // Calculate the hash value for the next window of text
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            // Ensure t is positive
            if (t < 0) {
                t = (t + q);
            }
        }
    }
    if (!found) {
        cout << "Not Found" << endl;
    }
}
int main() {
    string txt, pat;
    cin >> txt;
	cin >> pat;
    int q = 101; // A prime number
    rabinKarp(pat, txt, q);
    return 0;
}
