#include <iostream>

using namespace std;

struct Monster {
    string name;
    int x;
    int y;

    void moveNorth() {
        x -= 10;
    }
};

int main(int argc, char* argv[])
{
    Monster alex;
    alex.name = "Alex";
    alex.x = 100;
    alex.y = 101;

    alex.moveNorth();

    cout << alex.name << " is at (" << alex.x << "," << alex.y << ")";

    Monster ben;
    ben.name = "Ben";
    ben.x = 100;
    ben.y = 101;

    cout<<ben.name<<" "<<alex.name<<endl;
    ben = alex ;
    cout<<ben.name<<" "<<ben.x<<" "<<ben.y;

    return 0;
}

