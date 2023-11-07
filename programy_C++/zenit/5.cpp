#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int najvasci=0;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;

        if(najvasci<m){
            najvasci=m;
        }
    }
    n-=2;
    najvasci--;
    if(najvasci<n){
        cout<<najvasci<<endl;

    }
    else{
        cout<<n<<endl;
    }
}