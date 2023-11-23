#include <bits/stdc++.h>
using namespace std;

int main(){

int n;
cin>>n;
vector<vector<int>> v;
int medzi=0,vysledok=0;
for(int i=0;i<n;i++){
    vector<int> p;
    for(int j=0;j<4;j++){
        int a;
        cin>>a;
        p.push_back(a);
    }
    v.push_back(p);
}
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        if(i==j){
            continue;
        }
        for(int m=0;m<4;m++){
            int pomocna=v[i][m]-v[j][m];
            if(pomocna<0){
                pomocna*=-1;
            }
            medzi+=pomocna;
        }
        if(medzi>vysledok){
            vysledok=medzi;
        }
        medzi=0;





    }
}
cout<<vysledok<<endl;



}