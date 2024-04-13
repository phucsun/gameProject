#include<bits/stdc++.h>
using namespace std;


void in1(int n){
    cout<<&n<<endl;
}

void in2(int& n){
    cout<<&n<<endl;
}

int main(){
    int n ; cin>>n;
    cout<<&n<<endl;
    in1(n);
    in2(n);
}
