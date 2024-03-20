#include<bits/stdc++.h>
using namespace std;
int main(){
    int m , n ; cin>>m>>n;
    char s[m][n];
    for(int i=0 ; i< m ;i++){
        for(int j=0 ; j < n ;j++){
            cin>>s[i][j];
        }
    }
    for(int i=0 ; i < m ; i++){
        for(int j=0 ; j<n;j++){
            int cnt=0;
            if(s[i][j]=='*') continue;
            else{
                if(s[i-1][j-1]=='*' and i>0 and j>0) cnt++;
                if(s[i-1][j]=='*' and i>0) cnt++;
                if(s[i-1][j+1]=='*' and i>0 and j<n-1) cnt++;
                if(s[i][j-1]=='*' and j>0) cnt++;
                if(s[i][j+1]=='*' and j<n-1) cnt++;
                if(s[i+1][j-1]=='*' and i<m-1 and j>0) cnt++;
                if(s[i+1][j]=='*' and i<m-1) cnt++;
                if(s[i+1][j+1]=='*' and i<m-1 and j<n-1) cnt++;
                s[i][j]=cnt+'0';
            }
        }
    }
    for(int i=0 ; i< m ;i++){
        for(int j=0 ; j < n ;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }

}
