#include<bits/stdc++.h>
using namespace std;

int main(){
     int* p = new int;
     int* p2 = p;
     *p = 10;
     delete p;
    *p2 = 100;
     cout << *p2;
     delete p2; // loi o dong nay vi con tro p2 tro toi vung bo nho da duoc giai phong boi con tro p -> loi undefined behavior.
}
