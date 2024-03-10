#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int k=0;k<i-1;k++){
            cout<<" ";
        }
        for(int j=2*n-1;j>=2*i-1;j--){
            cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}
