#include <iostream>
using namespace std;
int main() {
    int x = 5;
    int* ptr = &x;

    cout<< x << endl;
    cout << *ptr << endl;

    delete ptr; // Giải phóng con trỏ

    cout << x << endl;
    cout<< *ptr << endl;
/*Ban đầu, một biến địa phương x được khởi tạo với giá trị là 5.
Sau đó, một con trỏ ptr được khởi tạo để trỏ tới x.
Chương trình in ra giá trị của x và giá trị mà con trỏ ptr trỏ tới, chúng đều là 5.
Tuy nhiên, khi chúng ta cố gắng giải phóng con trỏ ptr bằng delete ptr;, điều này dẫn đến một lỗi runtime. Lý do là x không được cấp phát bằng new, do đó không thể giải phóng bằng toán tử delete.
Sau khi cố gắng giải phóng con trỏ, chương trình sẽ gặp phải lỗi undefined behavior khi cố gắng truy cập x hoặc giá trị của con trỏ ptr.
*/
    return 0;
}

