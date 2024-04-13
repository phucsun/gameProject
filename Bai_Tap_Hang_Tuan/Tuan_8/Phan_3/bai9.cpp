#include <iostream>
using namespace std;
struct Point {
    int x, y;
};
void thamtri(Point p) {
    cout << &p << endl;
}
void thamchieu(Point& p) {
    cout << &p << endl;
}
int main() {
    Point point;
    point.x = 10;
    point.y = 20;
    cout << &point << endl;
    thamtri(point);
    cout << &point << endl;
    thamchieu(point);
    cout << &point << endl;

    return 0;
}
