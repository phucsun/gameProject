#include <iostream>
using namespace std;
struct Point {
    int x, y;
};
Point mid_point(const Point& p1, const Point& p2) {
    Point mid;
    mid.x = (p1.x + p2.x) / 2;
    mid.y = (p1.y + p2.y) / 2;
    return mid;
}
int main() {
    Point point1, point2;
    point1.x = 1;
    point1.y = 2;
    point2.x = 3;
    point2.y = 4;
    Point mid = mid_point(point1, point2);
    cout<< mid.x << " "<< mid.y << endl;

    return 0;
}
