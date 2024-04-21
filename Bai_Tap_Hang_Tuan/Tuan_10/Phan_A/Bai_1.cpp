#include <iostream>
#include <cstring>
using namespace std;
char* concat(const char* s1 , const char* s2){
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    char* res = new char[len1 + len2 + 1];
    strcpy(res, s1);
    strcat(res, s2);
    return res;
}

int main(){
    const char* s1 = "h";
    const char* s2 = "h";
    char* str = concat(s1, s2);
    cout << str << endl;
    delete[] str;
    return 0;
}
