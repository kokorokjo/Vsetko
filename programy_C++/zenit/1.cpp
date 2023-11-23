#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n;
    cin>>n;
    int a=0,b=0;
    int pocet=0,vysledok=0;
    vector<int> v;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        v.push_back(p);
    }
    int koniec=0;
    for(int i=0;i<n;i++){
        if(a==0){
            a=v[i];
        }
        if(b==0&&v[i]!=a){
            b=v[i];
        }
        if(v[i]!=a&&v[i]!=b){
            if(pocet>vysledok){
                vysledok=pocet;
            }
            koniec=i;
            pocet=2;
            a=v[i-1];
            for(int j=i-2;j>=0;j--){
                if(v[j]==a){
                    pocet++;
                }
                else{
                    break;
                }
            }
            b=v[i];
            
        }
        else{
            pocet++;
        }

    }
    if(pocet>vysledok){
        vysledok=pocet;
    }
    cout<<vysledok<<endl;
}