#include<bits/stdc++.h>
using namespace std;

void f(int xval)
{
   int x;
   x = xval;
   cout<<&x<<endl;
}
void g(int yval)
{
   int y;
   // in địa chỉ của y tại đây
   cout<<&y<<endl;
}
int main()
{
   f(7);
   g(11);
   return 0;
}

// x va y co cung dia chi
