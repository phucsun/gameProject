#include<bits/stdc++.h>
using namespace std;

struct String {
    int n; // Độ dài của xâu
    char* str; // Con trỏ đến mảng kí tự

    // Constructor
    String(const char* s) {
        n = strlen(s); // Độ dài của xâu
        str = new char[n + 1]; // Cấp phát động cho mảng kí tự, bao gồm kí tự kết thúc chuỗi '\0'
        strcpy(str, s); // Sao chép nội dung xâu s vào str
    }

    // Destructor
    ~String() {
        delete[] str; // Giải phóng bộ nhớ đã cấp phát động
    }

    // Hàm in nội dung xâu ra màn hình
    void print() const {
        cout << str << endl;
    }

    // Hàm nối thêm xâu vào cuối xâu
    void append(const char* s) {
        int len = strlen(s); // Độ dài của xâu thêm vào
        char* temp = new char[n + len + 1]; // Cấp phát mảng mới có độ dài đủ lớn
        strcpy(temp, str); // Copy nội dung xâu hiện tại vào temp
        strcat(temp, s); // Nối thêm xâu mới vào cuối xâu temp
        delete[] str; // Giải phóng bộ nhớ của str hiện tại
        str = temp; // Trỏ str tới mảng mới
        n += len; // Cập nhật độ dài của xâu
    }
};

int main() {
    // Khởi tạo một biến kiểu String và in nội dung ra màn hình
    String greeting("Hi");
    greeting.print();

    // Thêm xâu " there" vào cuối xâu và in lại nội dung ra màn hình
    greeting.append(" there");
    greeting.print();

    return 0;
}
