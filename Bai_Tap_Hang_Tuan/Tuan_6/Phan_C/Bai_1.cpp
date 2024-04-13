#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0));
    int m ,n ,k;
    cin>>m>>n>>k;
    int a[m][n]={0};

    for(int i=0;i<k;i++){
        int x = rand()%n;
        int y = rand()%m;
        a[x][y]=1;
    }
    int luot_choi = m*n - k;
    while(luot_choi--){
        int x , y ; cin>>x>>y;
        if(a[x][y]==1){
            cout<<"YOU'RE DEAD!"<<endl;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
            return 1;
        }
    }
    cout<<"YOU WIN!";
}
