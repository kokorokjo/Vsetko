#include <bits/stdc++.h>
using namespace std;
define mod=1000000007;

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        int idk;
        cin>>idk;
        vector<int> a(idk);
        a[0]=1;
        a[1]=1;
        for(int j=2;j<idk;j++){
            a[j]=a[j-1]+a[j-2];
        }
        v[i]=a[idk-1]%mod;
    }
    for(int i=0;i<n;i++){
        cout<<v[i]<<endl;
    }
}