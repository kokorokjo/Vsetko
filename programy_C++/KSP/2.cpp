#include <bits/stdc++.h>
#include <vector>
using namespace std;



int main(){
    vector <int> v;
    int a;
    cin >> a;
    for (int i = 0; i < a; i++){
        int b;
        cin >> b;
        v.push_back(b);
    }
    long long d = 0;
    long long p = 1;

    for (int i=0;i<v.size();i++){
        if (v[i] == 1){
            d += p;
        }
        p *= 2;
    }

    long long int o = 0;
    p = 1;
    for (int i=0;i<v.size();i++){
        o += p;
        p *= 2;
    }
    // cout << d << " " << o<<endl;
    cout<<o-d<<endl;

    return 0;
    



}