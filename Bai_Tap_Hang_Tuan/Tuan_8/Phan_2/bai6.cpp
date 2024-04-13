#include <iostream>
#include <string>
using namespace std;
struct Rect
{
    int x,y,w,h;
    Rect(int x1,int y1, int w1,int h1)
    {
        x=x1;
        y=y1;
        w=w1;
        h=h1;
    }
};
struct Ship{
    Rect rect;
    string id;
    int dx, dy;
    Ship(string id1,int dx1,int dy1,int x, int y, int w, int h) : id(id1), dx(dx1), dy(dy1),rect(x, y, w, h){
    }
    void move() {
        rect.x += dx;
        rect.y += dy;
    }
};
void display(const Ship& ship) {
    cout << ship.id << endl;
    cout << ship.rect.x << ' ' << ship.rect.y << endl;
}
int main() {
    Ship ship("AAA",5 , 5, 25 , 35, 15, 20);
    ship.move();
    display(ship);

    return 0;
}

