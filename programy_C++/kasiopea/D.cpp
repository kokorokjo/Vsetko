#include <bits/stdc++.h>
using namespace std;  


void rekurzia(vector<vector<pair<long long,long long>>> &hlavny, long long vrchol, vector<pair<long long ,long long>> &hodnoty,vector<int> &visited){
    visited[vrchol]=1;
    for(long long i=0;i<hlavny[vrchol].size();i++){

        if(hlavny[vrchol].size()==1){
            hodnoty[vrchol]={0,0};
            continue;
        }
        
        long long pomocny=hlavny[vrchol][i].first;
        long long cesta=hlavny[vrchol][i].second;
        if(visited[pomocny]==0){
            
            rekurzia(hlavny,pomocny,hodnoty,visited);


            if(hodnoty[vrchol].first<hodnoty[vrchol].second){
                if(hodnoty[vrchol].first<max(hodnoty[pomocny].first,hodnoty[pomocny].second)+cesta){
                hodnoty[vrchol].first=max(hodnoty[pomocny].first,hodnoty[pomocny].second)+cesta;
            }

            }
            else if(hodnoty[vrchol].second<max(hodnoty[pomocny].first,hodnoty[pomocny].second)+cesta){
                hodnoty[vrchol].second=max(hodnoty[pomocny].first,hodnoty[pomocny].second)+cesta;

            }
        }
        

    }


}



// prekazdy vrchol najdem najdlhsiu cestu do listu a cestu do rootu
//



int main(){
    long long t;
    ifstream in("D-tezky (2).txt");
    ofstream out("Doutput.txt");
    in >> t;
    for(long long all=0;all<t;all++){
        vector<long long> leafs;
        long long max=0;
        long long sucet=0;
        long long n;
        in >> n;
        if(n==1)
        {
            cout<<0<<endl;
            out<<0<<endl;
            continue;
        }
        vector<pair<long long ,long long>> hodnoty(n, {-1,-1});
        vector<int> visited(n,0);
        vector<vector<pair<long long ,long long>>> hlavny(n);
        for(long long i=1;i<n;i++){
            long long u;
            long long v;
            long long l;
            in >> u>>v>>l;
            u--;
            v--;
            hlavny[u].push_back(make_pair(v,l));
            hlavny[v].push_back(make_pair(u,l));
            sucet+=l;
        }

        for(long long i=0;i<n;i++){
            if(hlavny[i].size()==1){
                leafs.push_back(i);
            }
        }

        hlavny[leafs[0]].push_back(make_pair(leafs[0],0));
        rekurzia(hlavny,leafs[0],hodnoty,visited);
        for(long long i=0;i<n;i++){
            if(hodnoty[i].first==-1)
            hodnoty[i].first=0;
            if(hodnoty[i].second==-1)
            hodnoty[i].second=0;

            if(hodnoty[i].first+hodnoty[i].second>max){
                max=hodnoty[i].first+hodnoty[i].second;
            }
            
        }


        long long pomocna=sucet-max;
        cout<<pomocna*2+max<<endl;
        out<<pomocna*2+max<<endl;
       
    




    }
    in.close();
    out.close();
}