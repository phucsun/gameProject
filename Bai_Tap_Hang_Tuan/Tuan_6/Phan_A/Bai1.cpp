#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin>>n;
    int a[n];
    char b[n];
    for(int i=0;i<3;i++){
        cout<<&a[i]<<endl;
    }
// cac phan tu cach nhau 4 bit

    for(int i=0;i<3;i++){
        cout<<(void*)&b[i]<<endl;
    }

// cac phan tu cach nhau 1bit
}
