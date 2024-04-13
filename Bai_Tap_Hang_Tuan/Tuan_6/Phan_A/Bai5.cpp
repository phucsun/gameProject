#include <iostream>

int main() {
    int a = 10;
    int &ref_a = a; // Khai báo một biến tham chiếu và chiếu nó tới biến a

    std::cout << "Value of a: " << a << std::endl; // In giá trị của a
    std::cout << "Value of ref_a: " << ref_a << std::endl; // In giá trị của biến tham chiếu ref_a

    // Thay đổi giá trị của biến a thông qua biến tham chiếu ref_a
    ref_a = 20;

    std::cout << "New value of a: " << a << std::endl; // In giá trị mới của a sau khi thay đổi thông qua ref_a

    // Câu trả lời cho các câu hỏi:
    // 1. Biến tham chiếu và biến mà nó chiếu tới được coi là một biến duy nhất trong bộ nhớ. Khi thay đổi giá trị thông qua biến tham chiếu, giá trị của biến gốc cũng sẽ thay đổi.
    // 2. Không, một tham chiếu phải được khởi tạo ngay từ khi nó được khai báo và phải được chiếu tới một biến ngay lập tức.
    // 3. Không, một tham chiếu không thể thay đổi đích chiếu sau khi nó đã được khởi tạo. Tham chiếu được gắn với một biến duy nhất trong suốt vòng đời của nó.

    return 0;
}
