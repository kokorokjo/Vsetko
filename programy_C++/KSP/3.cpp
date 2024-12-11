#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int>> v(1,make_pair(-1,-1));

void prepis(int k){
    
    while (k>1){
        if(v[k/2].first == -1 || v[k/2].first>v[k].first){
            v[k/2].first = v[k].first;
        }
        if(v[k/2].second == -1 || v[k/2].second>v[k].second){
            v[k/2].second = v[k].second;
        }
        k = k/2;
    }
}

int main() {
    int n,t,p;
    cin>>n>>t>>p;
    int pred=0;
    int sucet=0;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(a<=b*t){
            p--;
            sucet+=pred;
        }
        else{
            pred++;
        }
        if(p=0){
            break;
        }
    }
    cout<<sucet<<endl;
    
}