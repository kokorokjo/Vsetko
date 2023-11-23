#include <bits/stdc++.h>
using namespace std;





int main(){
int n,k;
cin>>n>>k;
vector<int> v;
for(int i=0;i<n;i++){
    int a;
    cin>>a;
    v.push_back(a);
}
int vysledok=0;
for(int i=0;i+k<=n;i++){
    for(int j=i;j<i+k;j++){
        if(vysledok<v[j]){
            vysledok=v[j];
        
        }
    }
    cout<<vysledok;
    if(i+k!=n){
        cout<<" ";
    }
    else{
        cout<<endl;
    }
    vysledok=0;
}







}