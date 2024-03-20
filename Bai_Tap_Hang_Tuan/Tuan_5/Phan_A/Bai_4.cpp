#include <iostream>
using namespace std;
int main() {
    // Khai báo mảng và biến
    char arr[5];
    char var1, var2;

    // Đọc tràn
    cout <<endl;
    for (int i = -1; i <= 6; ++i) {
        cout << "arr[" << i << "]: " << arr[i] << endl;
    }
    cout << "var1: " << var1 << endl;
    cout << "var2: " << var2 << endl;

    // Ghi tràn
    cout <<endl;
    for (int i = -1; i <= 6; ++i) {
        arr[i] = 'A'; // Ghi tràn mảng
    }
    cout << "arr[-1]: " << arr[-1] << endl;
    cout << "arr[5]: " << arr[5] << endl;

    // Tràn mảng nhiều chiều
    char arr2D[3][4];
    cout << "\nOverflowing 2D array:" << endl;
    for (int i = 0; i < 4; ++i) {
        arr2D[0][i] = 'B'; // Ghi tràn hàng đầu tiên của mảng 2 chiều
    }
    // In mảng 2 chiều ra màn hình
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            cout << arr2D[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

