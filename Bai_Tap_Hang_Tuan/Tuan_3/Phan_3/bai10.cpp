#include <iostream>
#include <string>
using namespace std;

struct Point {
    int x, y;
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}
};

int main() {
    struct {
        int array[3];
    } struct1;
    struct1.array[0] = 1;
    struct1.array[1] = 2;
    struct1.array[2] = 3;
    auto struct2 = struct1;
    struct1.array[0] = 10;
    cout << struct2.array[0] << endl;
    struct {
        Point point;
    }struct3;
    struct3.point= Point(5, 5);
    auto struct4 = struct3;
    struct3.point.x = 10;
    cout << struct4.point.x << endl;

    return 0;
}

