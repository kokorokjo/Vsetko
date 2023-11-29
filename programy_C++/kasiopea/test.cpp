#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream MyReadFile("E-tezky (4).txt");
    int neviem;
    MyReadFile>>neviem;
    int pocet;
    MyReadFile>>pocet;
    cout<<pocet<<endl;
    vector<int> pocet_pismen(26,0);
    string k;
    MyReadFile>>k;
    for(int i=0;i<pocet;i++){
        string s;
        MyReadFile>>s;
        if(s.size()==1){

        
        cout<<s<<endl;
        }
    }
    for(int i=0;i<26;i++){
        cout<<pocet_pismen[i]<<" ";
    }//TGOIFH
    for(int i=0;i<k.size();i++){
        if(k[i]=='X'){
            cout<<"neviem"<<i<<endl;
        }
    }
    cout<<endl;

}