#include <bits/stdc++.h>
using namespace std;

int main(){

    long long z,k,p;
    bool zacia=true,koncia=true;
    cin>>z>>k>>p;
    vector<long long> v;

    for(int i=0;i<p;i++){
        long long a;
        cin>>a;
        v.push_back(a);
        if(a==z){
            zacia=false;
        }
        if(a==k){
            koncia=false;
        }
    
    }
    if(v.size()==0){
        cout<<k-z+1<<endl;
        return 0;
    }
    sort(v.begin(),v.end());
    long long pocet=0;
    if(zacia){
        if(v[0]-z>pocet){
            pocet=v[0]-z;
        }
    }
    if(koncia){
        if(k-v[v.size()-1]>pocet){
            pocet=k-v[v.size()-1];
        }
    }
    for(int i=0;i<v.size()-1;i++){
        if(v[i+1]-v[i]-1>pocet){
            pocet=v[i+1]-v[i]-1;
        }
    }
    cout<<pocet<<endl;


    
    
    return 0;


}