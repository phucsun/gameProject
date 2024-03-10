#include<bits/stdc++.h>
using namespace std;

struct String {
    int n;
    char* str;
    String(const char* s) {
        n = strlen(s);
        str = new char[n + 1];
        strcpy(str, s);}
    ~String() {delete[] str;}
    void print() const {cout << str << endl;}
    void append(const char* s) {
        int len = strlen(s);
        char* temp = new char[n + len + 1];
        strcpy(temp, str);
        strcat(temp, s);
        delete[] str;
        str = temp;
        n += len;
    }
};
int main() {
    String greeting("Hi");
    greeting.print();
    greeting.append(" there");
    greeting.print();
    return 0;
}
