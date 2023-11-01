#include <iostream>
#include <string>
using namespace std;

struct Match {
    string name;
    int stime;
    int ftime;
};
// Function to select and output non-overlapping activities
void selectActivities(Match m[], int n) {
    cout << "Selected Activities are:" << endl;
    cout << m[0].name << " ";
    int k = 0;
    for (int i = 1; i < n; i++) {
        if (m[i].stime >= m[k].ftime) {
            cout << m[i].name << " ";
            k = i;
        }
    }
}
int main() {
    int n, i, j;
    Match m[10000];
    Match temp;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> m[i].name;
        cin >> m[i].stime;
        cin >> m[i].ftime;
    }
    // Sort activities by finish time using the Bubble Sort algorithm
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (m[j].ftime > m[j + 1].ftime) {
                temp = m[j];
                m[j] = m[j + 1];
                m[j + 1] = temp;
            }
        }
    }
    selectActivities(m, n); // Call the function to select and output activities
    return 0;
}
