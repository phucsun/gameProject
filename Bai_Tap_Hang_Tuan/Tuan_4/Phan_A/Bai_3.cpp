#include <iostream>
using namespace std;
void printArray(char arr[][12], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << static_cast<int>(arr[i][j]) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    char daytab1[2][12] = {
        {31,28,31,30,31,30,31,31,30,31,30,31},
        {31,29,31,30,31,30,31,31,30,31,30,31}
    };
    char daytab2[2][12] = {
        31,28,31,30,31,30,31,31,30,31,30,31,
        31,29,31,30,31,30,31,31,30,31,30,31
    };

    printArray(daytab1, 2, 12);
    cout << "daytab2:" << std::endl;
    printArray(daytab2, 2, 12);


    char daytab1_partial[2][5] = {
        {31,28,31,30,31},
        {31,29,31,30,31}
    };
    char daytab2_partial[1][12] = {
        31,28,31,30,31,30,31,31,30,31,30,31
    };

    cout << "Partial Arrays:" << endl;
    cout << "daytab1_partial:" <<endl;
    printArray(daytab1_partial, 2, 5);
    cout << "daytab2_partial:" <<endl;
    printArray(daytab2_partial, 1, 12);

    char daytab3[][12] = {
        {31,28,31,30,31,30,31,31,30,31,30,31},
        {31,29,31,30,31,30,31,31,30,31,30,31}
    };
    char daytab4[2][] = {
        31,28,31,30,31,30,31,31,30,31,30,31,
        31,29,31,30,31,30,31,31,30,31,30,31
    };

    printArray(daytab3, 2, 12);

    printArray(daytab4, 2, 12);

    return 0;
}

