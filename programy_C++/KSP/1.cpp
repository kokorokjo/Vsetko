#include <bits/stdc++.h>
using namespace std;


int main(){
    long long s,n;
    cin>>s>>n;
    long long pocitadlo=0;
    long long vysledok=0;
    long long kde=0;
    for(long long i=0;i<n;i++){
        long long v,k;
        cin>>v>>k;
        if(k==1){
            pocitadlo+=v;
            kde=i;
            if(pocitadlo==s)
            {
                vysledok++;
                
            }
            break;

        }
        kde=i;
    }
    for(long long i=kde+1;i<n;i++){
        long long v,k;
        cin>>v>>k;
        if(k==0){
            pocitadlo+=v;
            if(pocitadlo==s)
            {
                vysledok++;
                
            }
        }
        else{
            pocitadlo=v;
            if(pocitadlo==s)
            {
                vysledok++;
                
            }
        }
    }
    cout<<vysledok<<endl;
    

    
}
