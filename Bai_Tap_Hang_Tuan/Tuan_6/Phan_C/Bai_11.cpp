#include<bits/stdc++.h>
using namespace std;

string decimal_to_binary(int x){
    string res="";
    while(x){
        int tmp = x%2;
        res+= to_string(tmp);
        x/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}

int main(){
    int x; cin>>x;
    cout<<decimal_to_binary(x);
}
