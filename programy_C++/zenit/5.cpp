#include <bits/stdc++.h>
using namespace std;

bool dobre=true;

void rekurzia(vector<int> &v,vector<vector<int>> &v3,int l,int r){
    if(v[l]==v[r]){
        int neviem=v3[l].size()+1;
        for(int i=0;i<neviem/2;i++){
            rekurzia(v,v3,v3[l][i],v3[r][v3[r].size()-1-i]);
        }
    }
    else{
        dobre=false;
    }
}

int main(){
    int n;
    cin>>n;
    int r=0,l=0;
    vector<int> v(n,-1);
    vector<vector<int>> v3(n);
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v[i]=a;
        vector<int> v2;
        for(int j=0;j<a;j++){
            int b;
            cin>>b;
            v2.push_back(b);
        }
        v3[i]=v2;
    }
    rekurzia(v,v3,0,0);
    if(dobre==true)
    cout<<"^_^"<<endl;
    else
    cout<<"O_o"<<endl;
}