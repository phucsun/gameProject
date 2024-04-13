#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char *argv[]) {
    const char* str1 = argv[1];
    const char* str2 = argv[2];

    int count = 0;
    int str1Len = strlen(str1);
    int str2Len = strlen(str2);

    for (int i = 0; i <= str2Len - str1Len; ++i) {
        if (strncmp(&str2[i], str1, str1Len) == 0) {
            count++;
        }
    }

    cout<<count;
    return 0;
}
