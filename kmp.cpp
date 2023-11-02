#include <iostream>
#include <vector>
#include <string>
using namespace std;
void computeLPSArray(string pat, int M, vector<int> lps) {
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = len;
                i++;
            }
        }
    }
}
void KMPSearch(string pat,string txt) {
    int M = pat.length();
    int N = txt.length();
    vector<int> lps(M);
    int j = 0;
    computeLPSArray(pat, M, lps);
    bool found = false;
    int i = 0;
    while (N - i >= M - j) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            found = true;
            cout << "Found at " << (i - j) <<endl;
            j = lps[j - 1];
        } else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    if (!found)
        cout << "Not Found" << endl;
}
int main() {
    string txt, pat;
    cin >> txt >> pat;
    KMPSearch(pat, txt);
    return 0;
}
