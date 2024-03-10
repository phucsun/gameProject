#include <iostream>
#include <vector>

using namespace std;

void magicSquare(int N) {
    vector<vector<int>> matrix(N, vector<int>(N, 0));

    // Khởi tạo vị trí bắt đầu là hàng giữa và cột cuối cùng
    int row = N / 2;
    int col = N - 1;

    // Điền các số vào ma trận
    for (int num = 1; num <= N * N;) {
        // Nếu hàng và cột vượt ra khỏi giới hạn của ma trận
        if (row == -1 && col == N) {
            col = N - 2;
            row = 0;
        } else {
            // Nếu cột vượt ra khỏi giới hạn của ma trận
            if (col == N) {
                col = 0;
            }
            // Nếu hàng vượt ra khỏi giới hạn của ma trận
            if (row < 0) {
                row = N - 1;
            }
        }

        // Nếu ô đã được điền
        if (matrix[row][col] != 0) {
            col -= 2;
            row++;
            continue;
        } else {
            // Gán số vào ô hiện tại
            matrix[row][col] = num++;
        }

        // Đi lên trên một dòng và sang trái một cột
        col++;
        row--;
    }

    // In ma trận kì ảo
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;
    magicSquare(N);
    return 0;
}

