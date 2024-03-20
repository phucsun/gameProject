#include <iostream>
using namespace std;

// Hàm tính giai thừa
int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

// Hàm tính toán hệ số nhị thức (n choose k)
int binomialCoefficient(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}

// Hàm để in tam giác Pascal
void printPascalTriangle(int n) {
    for (int line = 0; line < n; line++) {
        // In các khoảng trắng để căn lề
        for (int i = 0; i < n - line - 1; i++)
            cout << " ";

        // In các hệ số của tam giác Pascal cho dòng hiện tại
        for (int i = 0; i <= line; i++)
            cout << binomialCoefficient(line, i) << " ";

        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    printPascalTriangle(n);
    return 0;
}
