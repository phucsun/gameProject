#include<bits/stdc++.h>
using namespace std;

struct Point
{
    int p1;
    int p2;
    Point(int p3,int p4){
    p1=p3;
    p2=p4;
    }
};
struct Rect{
    int x,y,w,h;
    Rect(int toadox,int toadoy,int ngang,int cao)
    {
        x=toadox;
        y=toadoy;
        w=ngang;
        h=cao;
    }
    bool contains(Point &p){
        if(p.p1>=x && p.p1<=x+w && p.p2>=y && p.p2<=y+h){return true;}
        else return false;
    }
};
int main()
{
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    Rect rect(x,y,w,h);
    int p1,p2;
    cin>>p1>>p2;
    Point point(p1,p2);
    cout<<rect.contains(point);
}
