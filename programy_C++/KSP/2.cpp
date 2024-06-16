#include <bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<int> ostatne,kladne,zaporne;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==0){
            ostatne.push_back(a);
        }
        else if(a<0){
            zaporne.push_back(a);
        }
        else if(a>0){
            kladne.push_back(a);
        }
    }
    cout<<zaporne.size();
    for(int i=0;i<zaporne.size();i++){
        cout<<" "<<zaporne[i];
    }
    cout<<endl;
    cout<<kladne.size();
    for(int i=0;i<kladne.size();i++){
        cout<<" "<<kladne[i];
    }
    cout<<endl;
    cout<<ostatne.size();
    for(int i=0;i<ostatne.size();i++){
        cout<<" "<<ostatne[i];
    }
    cout<<endl;

    



}