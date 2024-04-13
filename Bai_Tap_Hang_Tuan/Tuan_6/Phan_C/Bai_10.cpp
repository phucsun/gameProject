#include<bits/stdc++.h>
using namespace std;

int d[50];
int main(){
    srand(time(0));
    int  n ;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        a[i]= rand()%50;
        d[a[i]]++;
    }
    if(d[0]>3) cout<<"0 0 0"<<endl;
    for(int i=0;i<=49;i++){
        for(int j=i+1;j<=49;j++){
            for(int k=j+1;k<=49;k++){
                if((i+j+k)%25==0 and d[i]>0 and d[j]>0 and d[k]>0) cout<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    }

}
