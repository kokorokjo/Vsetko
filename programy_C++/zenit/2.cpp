#include <bits/stdc++.h>   
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
    vector<char> v;
    for(int i=0;i<9;i++){
        
            char a;
            cin>>a;
            v.push_back(a);
    }
    for(int i=0;i<r;i++){
        string riadok;
        cin>>riadok;
        for(int j=0;j<c;j++){
            char nieco2=riadok[j];
            int nieco=nieco2-48;
            if(nieco<10&&nieco>0){
                cout<<v[nieco-1];
            }
            else{
            
                cout<<nieco2;
            }
        }
        cout<<endl;
    }    
}