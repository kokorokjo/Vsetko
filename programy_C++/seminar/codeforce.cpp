#include<bits/stdc++.h>
using namespace std;



int main(){
    long long t,n,x;
    cin>>t;
    vector<long long> vysledky(t);
    for(long long neviem=0;neviem<t;neviem++){
        cin>>n>>x;
        vector<long long> v(n);
        for(long long j=0;j<n;j++){
            cin>>v[j];
        }
        sort(v.begin(),v.end());
        long long pocet=0;
        long long vyska=0;
        long long index=0;
        vyska=v[0];
        bool bol=false;
        while(pocet<x){
        if(index+1==n){
            long long nieco=x-pocet;
            vyska+=nieco/(index+1);
            bol=true;
            break;
        }
        else{
            index++;
            pocet+=index*(v[index]-vyska);
            vyska=v[index];

        }
        }
        if(bol){
            vysledky[neviem]=vyska;
        }
        else{
            for(long long i=v[index];i>v[index-1];i--){
                pocet-=index;
                vyska--;
                if(pocet<=x){
                    vysledky[neviem]=vyska;
                    break;
                }
            }
        }
    }
    for(auto i:vysledky){
        cout<<i<<endl;
    }
    
}