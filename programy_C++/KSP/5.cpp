#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    vector<int> b(n,-1);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    for(int i=n-1;i>=0;--i){
        int p=a[i];
        int pozicia=i;
        int pocitadlo=0; 
        int min=INT_MAX;
        while(true){
            pozicia+=p;
            pocitadlo++;
            if(pozicia>=n){
                if(pocitadlo<min){
                    min=pocitadlo;
                }
                b[i]=min;
                break;
            }
            if(a[pozicia]==p){
                if(b[pozicia]+pocitadlo<min){
                b[i]=b[pozicia]+pocitadlo;
                break;
            }
            }
            if(b[pozicia]+pocitadlo<min){
                min=b[pozicia]+pocitadlo;
            }


        }
    }

    
    cout<<b[0]<<endl;

}