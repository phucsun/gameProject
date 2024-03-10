#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int start = 1;

    int a[x][y];
    int r1 = 0;
    int r2 = x - 1;
    int c1 = 0;
    int c2 = y - 1;
    while (r1 <= r2 and c1 <= c2) {
        for (int i = c1; i <= c2; i++) {
            a[r1][i] = start;
            start++;
        }
        r1++;
        for (int i = r1; i <= r2; i++) {
            a[i][c2] = start;
            start++;
        }
        c2--;
        if (r1 <= r2) {
            for (int i = c2; i >= c1; i--) {
                a[r2][i] = start;
                start++;
            }
            r2--;
        }
        if (c1 <= c2) {
            for (int i = r2; i >= r1; i--) {
                a[i][c1] = start;
                start++;
            }
            c1++;
        }
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
