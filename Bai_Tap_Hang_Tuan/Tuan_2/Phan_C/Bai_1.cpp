#include<bits/stdc++.h>
using namespace std;


bool Prime(int x){
    if(x<=1) return false;
    for(int i=2 ; i<=sqrt(x) ;i++){
        if(x%i==0) return false;
    }
    return true;
}
int main(){
    int x ; cin>>x;
    if(Prime(x)) cout<<"yes";
    else cout<<"no";
}
