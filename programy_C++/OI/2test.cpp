#include <bits/stdc++.h>    
using namespace std;

int main(){
    int kos,n,d;
    cin>>kos>>n>>d;
    vector<int> hlavny(n+1);
    for(int i=0;i<n;i++){
        cin>>hlavny[i];
    }
    hlavny[n]=-1;
    vector<vector<pair<int,int>>> pozicie(n);
    vector<int> posledny(n,-1);
    vector<int> dlzka(n,1);
    for(int i=0;i<n;i++){
        int pocet=1;
        while(hlavny[i]==hlavny[i+1]){
            pocet++;
            i++;
        }
        for(int j=0;j<pocet;j++){
            dlzka[i-j]=pocet;
        }
        posledny[hlavny[i]]=i;
    }





    //koniec
    for(auto i:hlavny){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:posledny){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:dlzka){
        cout<<i<<" ";
    }
    cout<<endl;

}