#include <bits/stdc++.h>   
using namespace std;


int main(){
    long long n;
    cin>>n;
    long long vysledok=1;
    vector<long long> v;
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;
        v.push_back(a);

    }
    for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           if(i!=j){
               vysledok*=v[j];
               vysledok%=1000000007;
           }
       }
       cout<<vysledok;
       vysledok=1;
       if(i!=n-1){
           cout<<" ";
       }
       else{
           cout<<endl;
       }
    }
}