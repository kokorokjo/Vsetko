#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    bool sedi=true;
    bool bol=false;
    bool koniec=false;
    int pocitadlo=0+n+n-1;
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<pair<int,int>> pary;

    for (int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int g=0; g<pary.size(); g++) {
                if(pary[g].first>=i && pary[g].second<=j) {
                    koniec=true;
                }
            }
            if(koniec) {
                koniec=false;
                continue;
            }
            for(int k = i+1; k < j; k++) {
                bol=true;
                int v1=abs(v[i]-v[j])+abs(i-j);
                int v2=abs(v[i]-v[k])+abs(i-k);
                int v3=abs(v[j]-v[k])+abs(j-k);
                if(v1==v2+v3 || v2==v1+v3 || v3==v1+v2) {
                    sedi=false;
                    pary.push_back({i,j});
                }
            }
            if(sedi && bol) pocitadlo++;
            sedi=true;
            bol=false;
        }
    }
    cout<<pocitadlo<<endl;
    
}