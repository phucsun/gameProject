#include <iostream>
using namespace std;

struct Point {
    int x, y;
    Point(int _x,int _y)
    {
        x=_x;
        y=_y;
    }
};

int main() {
    Point p(2,5);
    cout<< &p.x << endl;
    cout<< &p.y << endl;
    cout<<&p.y- &p.y;

    return 0;
}
