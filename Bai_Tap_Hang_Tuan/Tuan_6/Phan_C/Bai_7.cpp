#include <iostream>

void printIsoscelesTriangle(int height) {
    for (int i = 1; i <= height; ++i) {
        for (int j = 1; j <= height - i; ++j) {
            std::cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; ++j) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main() {
    int height;
    std::cin >> height;

    printIsoscelesTriangle(height);

    return 0;
}

