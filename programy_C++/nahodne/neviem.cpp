#include <bits/stdc++.h>
using namespace std;


bool dfs(int b, vector<vector<int>> & hlavny, vector<int> & vedlajsi, vector<int> bol){
    if(vedlajsi[b]==-1)return 1;
    int a = vedlajsi[b];
    bol[b]=1;
    for(int e:hlavny[a])
    if(!bol[e] && dfs(e,hlavny,vedlajsi, bol)){
        vedlajsi[e]=a;
        return 1;
    }
return 0;

}




int main(){
    int n,m,p;
    cin>>n>>m>>p;
    vector<vector<int> >hlavny(n);
    vector<int> vedlajsi(m,-1);
    for(int i=0;i<p;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        hlavny[a].push_back(b);
    }
    
    cout<<prve(hlavny,vedlajsi)<<endl;
    for(int i=0;i<m;i++){
        if(vedlajsi[i]!=-1){
            cout<< vedlajsi[i]+1<<" "<<i+1<<endl;
        }
    }
    return 0
    

}