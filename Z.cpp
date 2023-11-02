#include <iostream>
#include <vector>
#include <string>
using namespace std;
void getZarr(string str, vector<int> Z) {
    int n = str.length();
    int L = 0, R = 0;
    for (int i = 1; i < n; ++i) {
        if (i > R) {
            L = R = i;
            while (R < n && str[R - L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        } else {
            int k = i - L;
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];
            else {
                L = i;
                while (R < n && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}
void zAlgo(string text, string pattern) {
    string concat = pattern + "$" + text;
    int l = concat.length();
    vector<int> Z(l, 0);
    bool found = false;
    getZarr(concat, Z);
    for (int i = 0; i < l; ++i) {
        if (Z[i] == pattern.length()) {
            cout << "Found at " << (i - pattern.length() - 1) <<endl;
            found = true;
        }
    }
    if (!found)
        cout << "Not Found" <<endl;
}
int main() {
    string text, pattern;
    cin >> text >> pattern;
    zAlgo(text, pattern);
    return 0;
}
