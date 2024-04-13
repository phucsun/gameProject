#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_SIZE = 10;

void generateMineField(vector<vector<char>>& mineField, int m, int n, int K) {
    srand(time(NULL));
    int count = 0;
    while (count < K) {
        int x = rand() % m;
        int y = rand() % n;
        if (mineField[x][y] != '*') {
            mineField[x][y] = '*';
            ++count;
        }
    }
}

void displayMineField(const vector<vector<char>>& mineField, int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << mineField[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(int x, int y, int m, int n) {
    return x >= 0 && x < m && y >= 0 && y < n;
}

int countAdjacentMines(const vector<vector<char>>& mineField, int x, int y, int m, int n) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (isValid(x + i, y + j, m, n) && mineField[x + i][y + j] == '*') {
                ++count;
            }
        }
    }
    return count;
}

int main() {
    int m, n, K;
    cin >> m >> n;
    cin >> K;

    if (m > MAX_SIZE || n > MAX_SIZE || K >= m * n) {
        return 1;
    }

    vector<vector<char>> mineField(m, vector<char>(n, '.'));

    generateMineField(mineField, m, n, K);
    displayMineField(mineField, m, n);

    int x, y;
    while (true) {
        cin >> x >> y;
        if (mineField[x][y] == '*') {
            cout << "YOU'RE DEAD!" << endl;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (mineField[i][j] == '*') {
                        cout << "* ";
                    } else {
                        cout << mineField[i][j] << " ";
                    }
                }
                cout << endl;
            }
            break;
        } else {
            int adjacentMines = countAdjacentMines(mineField, x, y, m, n);
            mineField[x][y] = ' ';
            displayMineField(mineField, m, n);
        }
    }

    return 0;
}
