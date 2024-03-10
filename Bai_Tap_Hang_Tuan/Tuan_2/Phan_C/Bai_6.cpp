#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ; cin>>n;
    int d[n+1];
    for(int i=0 ; i<n;i++){
        d[i]=i+1;
    }
    int a[n][n];
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j < n ; j++){
            a[i][j]=d[j];
        }
        int tmp=d[0];
        for(int i=0 ; i < n ; i++){
            d[i]=d[i+1];
        }
        d[n-1]=tmp;
    }
    for(int i=0 ; i < n ; i++){
        for(int j=0 ; j<n ; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
