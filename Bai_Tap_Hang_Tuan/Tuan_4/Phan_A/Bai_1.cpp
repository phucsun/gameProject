#include <iostream>

int globalArray[5];


int main() {
    int array1[6] = {1, 2, 3, 4};
    int array2[3] = {1, 2, 3, 4};


    int array3[] = {1, 2, 3, 4};


    std::cout << "Contents of array1: ";
    for (int i = 0; i < 6; ++i) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;


    std::cout << "Contents of array3: ";
    for (int i = 0; i < sizeof(array3) / sizeof(array3[0]); ++i) {
        std::cout << array3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

