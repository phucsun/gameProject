#include <iostream>
using namespace std;

const int MAX = 100;

int toHop(int k, int n) {
    if (k == 0 || k == n)
        return 1;
    return toHop(k - 1, n - 1) + toHop(k, n - 1);
}

int kiemTra(int k, int n) {
    return (k >= 0 && k <= n && n >= 1 && n <= 20);
}

void nhapKN(int k[], int n[], int *soPhanTu) {
    *soPhanTu = 0;
    while (true) {
        int ki, ni;
        cin >> ki >> ni;
        if (ki == -1 && ni == -1)
            break;
        if (kiemTra(ki, ni)) {
            k[*soPhanTu] = ki;
            n[*soPhanTu] = ni;
            (*soPhanTu)++;
        }
    }
}

int main() {
    int k[MAX], n[MAX], soPhanTu;

    nhapKN(k, n, &soPhanTu);

    for (int i = 0; i < soPhanTu; ++i) {
        cout <<toHop(k[i], n[i]) << endl;
    }

    return 0;
}
