#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> hlavny(n);
    vector<int> idk(n,0);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        hlavny[b].push_back(a);
        hlavny[a].push_back(b);
    }

}