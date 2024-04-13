#include <iostream>
#include <vector>

using namespace std;

const int WIDTH = 7;
const int HEIGHT = 6;

void draw(vector<vector<char>>& image, int width, int height, int x, int y) {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cout << image[i][j];
        }
        cout << endl;
    }
}

void draw(vector<vector<char>>& image, const string& text, int x, int y) {
    int startX = x;
    for (char ch : text) {
        if (ch == '\n') {
            y++;
            x = startX;
            continue;
        }
        draw(image, WIDTH, HEIGHT, x, y);
        x += WIDTH + 1; // Add spacing between characters
    }
}

int main() {
    vector<vector<char>> letterA = {
        {' ', '#', '#', '#', ' ', ' ', '#', '#', '#', ' '},
        {'#', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', ' ', ' ', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', '#', ' ', ' ', ' ', '#'}
    };

    vector<vector<char>> letterK = {
        {'#', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', '#', ' ', ' ', '#', ' ', ' ', '#'}
    };

    vector<vector<char>> letterV = {
        {'#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#'},
        {'#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' '}
    };

    draw(letterA, "A", 0, 0);
    draw(letterK, "K", 10, 0);
    draw(letterV, "V", 20, 0);

    return 0;
}

