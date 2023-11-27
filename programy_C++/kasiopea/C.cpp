#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream MyFileRead("C-tezky (1).txt");
    int t;
    MyFileRead >> t;
    vector<long long> vysledky;
    for(int all=0;all<t;all++){
    int n;
    MyFileRead >> n;
    vector<long long> vsetko;
    vector<pair<long long,long long>> pozicia(n+1,make_pair(-1,-1));
    for(int i=0;i<2*n;i++){
        long long pomocna;
        MyFileRead >> pomocna;
        vsetko.push_back(pomocna);
        if(pozicia[pomocna].first==-1){
            pozicia[pomocna].first=i;
        }
        else{
            pozicia[pomocna].second=i;
        }
    }
    long long vysledok=0;
    int kde=0;
    for(int i=0;i<2*n;i++){
        if(pozicia[vsetko[i]].first==-1)continue;
        vysledok+=abs(kde-i);
        long long miesto1=i;
        long long miesto2=pozicia[vsetko[i]].second;
        cout<<miesto1<<" "<<miesto2<<endl;
        vysledok+=miesto2-miesto1;
        kde=miesto2;
        pozicia[vsetko[i]].first=-1;
        pozicia[vsetko[i]].second=-1;
    }


    vysledky.push_back(vysledok);
    }
    MyFileRead.close();
    ofstream MyFile("C.txt");
    for(auto i:vysledky){
        MyFile << i << endl;
    }
    MyFile.close();
    

}