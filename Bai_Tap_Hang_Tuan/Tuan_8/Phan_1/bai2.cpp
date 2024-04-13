#include <iostream>
using namespace std;

struct Point {
    int x, y;
};
void thambien(Point &p) {
    p.x = 20;
    p.y = 30;
}
void thamtri1(Point p) {
    p.x = 40;
    p.y = 50;
    cout << p.x << " " << p.y << endl;
}
void thamtri2(Point p) {
    p.x = 40;
    p.y = 50;
}
int main() {
    Point point;
    point.x = 10;
    point.y = 12;
    cout << point.x << " " << point.y << endl;
    thamtri1(point);
    thamtri2(point);
    cout << point.x << " " << point.y << endl;
    thambien(point);
    cout << point.x << " " << point.y << endl;
    return 0;
}
