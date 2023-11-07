#include <bits/stdc++.h>
using namespace std;

vector<int> prve(vector<vector<int>>&g,int n,int m){
    vector<int> z_b_do_a(m,-1);
    int res =najvacsie_parenie(g, z_b_do_a);
    vector<bool> X(n,true),Y(m);

for(int b:z_b_do_a) if(b!=-1) X[b]=false;
vector<int> C,q;x
for(int i=0;i<a;i++) if(X[i]) q.push_back(i);
while(!q,empty()){
    int a=q.back;q.pop_back;
    X[a]=true;
    for(int b:g[a])if(!Y[b] && z_b_do_a[b]!=-1){
        Y[b]=true;
        q.push_back(z_b_do_a[b]);
    }
}
    for(int i=0;i<n;i++)if(!X[i])C.push_back(i);
    for(int i=0;i<m;i++)if(Y[i])C.push_back(n+i);
    return C;

}





int main(){
    
}