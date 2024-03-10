#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    vector<int> v;
    while(cin>>x){
        v.push_back(x);
        if(x<0) break;
    }

    for(int i=0 ; i< (int)v.size() ; i++){
        if(v[i] != v[i-1]) cout<<v[i]<<" ";
    }
}

