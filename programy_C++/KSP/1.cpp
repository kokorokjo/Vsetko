#include <bits/stdc++.h>
using namespace std;


int main(){

    int n,k,pocet=0;
    int naj1=0,naj2=0;
    cin>>n;
    pocet=n-2;
    for(int i=0;i<n;i++){
        cin>>k;
        if(k>naj1){
            naj2=naj1;
            naj1=k;
        }
        else if(k>naj2){
            naj2=k;
        }
        if(k<1){
            pocet--;
        }
    }
    if(naj2-1<1){
        cout<<0<<endl;
        return 0;
    }
    if(naj2-1<pocet){
        cout<<naj2-1<<endl;
        return 0;
    }
    cout<<pocet<<endl;
}