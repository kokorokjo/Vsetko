#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n=2;
    long long r;
    cin >> r;
    n = pow(n,r+1);
    vector<long long> hlavny(n,0);
    vector<vector<long long>> vedlajsi (n, vector<long long>(19,-1));
    for(long long i=n-1;i>0;i--){
        long long p;
        cin >> p;
        if(i>=n/2){
            vedlajsi[i][p]=0;
        }
        hlavny[i]=p;
        // cout<<i<<endl;
   }
   for(long long i=n-1;i>=n/2;i--){
    for(long long j=17;j>=0;j--){
        if(vedlajsi[i][j+1]!=-1){
            vedlajsi[i][j]=vedlajsi[i][j+1];
        }
    }
   }
    for(long long i=n/2-1;i>0;i--){
    long long dalsi = -1; 
        for(long long k=17;k>=0;k--){
            if(vedlajsi[i*2][k]!=-1&&vedlajsi[i*2+1][k]!=-1){
                long long sucet = vedlajsi[i*2][k]+vedlajsi[i*2+1][k]+hlavny[i];
                if(dalsi!=-1){
                    vedlajsi[i][k]=min(sucet,dalsi);
                }
                else{
                    vedlajsi[i][k]=sucet;
                }
                if(dalsi!=-1){
                dalsi = min(dalsi,sucet-hlavny[i]);
                }
                else{
                    dalsi = sucet-hlavny[i];
                }
                
            }
        }
        
   }
    long long naj=1000000000000000000;
   for(auto i : vedlajsi[1]){
       if(i!=-1){
           naj = min(naj,i);
       }
   }
   cout<<naj<<endl;
    return 0;



}