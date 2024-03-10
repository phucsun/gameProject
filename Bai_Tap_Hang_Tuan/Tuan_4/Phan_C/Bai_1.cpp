#include<bits/stdc++.h>
using namespace std;
int main(){
    int n ; cin>>n;
    int a[n];
    int dd[n+1]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        dd[a[i]]++;
        if(dd[a[i]]>1){
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}


