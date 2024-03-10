#include<bits/stdc++.h>
using namespace std;

int Cnt(string s){
    int n =s.length();
    set<string> se;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            string sub_string= s.substr(0,i)+s.substr(i+1,j-i-1)+s.substr(j+1);
            se.insert(sub_string);
        }

    }
    return se.size();
}


int main(){
    string s;
    cin>>s;
    cout<<Cnt(s);
}
