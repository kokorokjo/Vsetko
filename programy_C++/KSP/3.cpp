#include <bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int pocitadlo=0+n+n-1;
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                int v1=abs(v[i]-v[j])+abs(i-j);
                int v2=abs(v[i]-v[k])+abs(i-k);
                int v3=abs(v[j]-v[k])+abs(j-k);
                if(v1!=v2+v3 && v2!=v1+v3 && v3!=v1+v2) {
                    pocitadlo++;
                }
            }
        }
    }
    cout<<pocitadlo<<endl;
    
}