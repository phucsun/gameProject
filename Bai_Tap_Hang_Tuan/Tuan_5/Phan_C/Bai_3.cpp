#include<bits/stdc++.h>
using namespace std;

int main(){
    int n ; cin>>n;
    string s = std::to_string(n);
    string s_=s;
    reverse(s.begin() , s.end());
    if(s_==s) cout<<"Yes";
    else cout<<"No";
}
