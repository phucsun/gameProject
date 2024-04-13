#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    cout << "n = " << n << " at " << &n << std::endl;
    if(n==1) return 1;
    else return n*factorial(n-1);
}


int main(){
    int n ; cin>>n;
    cout<<factorial(n);
}
// moi so cach nhau 30bit
// stack frame co kich thuoc khoang 30*n bit
