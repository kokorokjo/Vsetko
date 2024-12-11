#include <bits/stdc++.h>
using namespace std;



int main() {
    int n,t,p;
    cin>>n>>t>>p;
    int pred=0;
    int sucet=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a<=b*t){
            p--;
            sucet+=pred;
        }
        else{
            pred++;
        }
        if(p=0){
            break;
        }
    }
    cout<<sucet<<endl;
    
}