#include <bits/stdc++.h>
using namespace std;

void daco(int a,int b){
    if(a==0){
        cout<<endl;
    }
    else{
        for(int i=0;i<b;i++){
            char c = 'A';
            c+=i;
            cout<<c;
            daco(a-1,b);
        }
    }
    
    
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a,b;
    cin>>a>>b;
    daco(a,b);
}