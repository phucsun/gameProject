#include <iostream>
#include <cstring>
using namespace std;

void printCharArray(const char arr[], int size) {
    cout << "Array content: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i];
    }
    cout <<endl;
    cout << "String: " << arr <<endl;
}

int main() {
    char globalCharArray[10];
    char array1[5] = "abcd";
    char array2[3] = "abcd";
    char array3[] = "abcd";
    int sizeOfArray3 = sizeof(array3);

    printCharArray(globalCharArray, 10);
    printCharArray(array1, 5);
    printCharArray(array3, sizeOfArray3);

    return 0;
}

