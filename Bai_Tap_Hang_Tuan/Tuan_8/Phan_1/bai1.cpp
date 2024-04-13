#include <iostream>

using namespace std;

struct Point {
    int x, y;

};
void print(Point p) {
    cout << p.x << ' ' << p.y;}
int main()
{
   Point point;
   point.x = 10;
   point.y = 12;
   print(point);
}
