#include <iostream>
#include <string>
using namespace std;

void search(string pat, string txt) {
    int l1 = pat.length();
    int l2 = txt.length();
    for (int i = 0; i <= l2 - l1; i++) {
        int j;
        for (j = 0; j < l1; j++) {
            if (txt[i + j] != pat[j]) {
                break;
            }
        }
        if (j == l1) {
            cout << "Found at " << i << endl;
            return;
        }
    }
    cout << "Not Found" << endl;
}
int main() {
    string pat, txt;
	cin >> pat;
    cin >> txt;
    search(pat, txt);
    return 0;
}
