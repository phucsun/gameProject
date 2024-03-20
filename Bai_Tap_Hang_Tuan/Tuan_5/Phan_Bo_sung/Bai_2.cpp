#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int maxx = a[0];
    int minn = a[0];
    long long tong = 0;
    int cnt =0;
    for(int i=0;i<n;i++){
        if(a[i]>maxx){
            maxx=a[i];
        }
        if(a[i]<minn) minn=a[i];
        if(a[i]%2==0) tong+=a[i];
        if(a[i]%2!=0) cnt++;
    }
    cout<<maxx<<endl;
    cout<<minn<<endl;
    cout<<tong<<endl;
    cout<<cnt<<endl;
}
