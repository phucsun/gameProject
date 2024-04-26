#include<bits/stdc++.h>
using namespace std;
#include <cstring>

char* is_palindrome(const char* str) {
    int length = strlen(str);
    char* reversed_str = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        reversed_str[i] = str[length - i - 1];
    }
    reversed_str[length] = '\0';
    return reversed_str;
}
int main() {
    const char* stringg = "Hello Word";
    char* result = is_palindrome(stringg);
    cout <<result << endl;
    delete[] result;
    return 0;
}
