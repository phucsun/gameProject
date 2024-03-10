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
    Ship ship1("AAA",5 , 10, 15 , 20, 25, 30);
    Ship ship2("BBB", 1 , 2 , 3  , 4 , 5, 6);
    int loop=0;
    while (loop < 10) {
        ship1.move();
        ship2.move();
        display(ship1);
        display(ship2);
        loop++;
    }

    return 0;
}


