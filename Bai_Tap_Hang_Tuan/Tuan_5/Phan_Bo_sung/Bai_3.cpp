#include<bits/stdc++.h>
using namespace std;

int dd[10];
int main(){
    int n ; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        dd[a[i]]++;
    }

    for(int i=1;i<=9;i++){
        cout<<dd[i]<<endl;
    }
}
