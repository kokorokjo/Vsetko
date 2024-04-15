#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<pair<string,int>> hlavny,int start,int end,string to){
    int stred=(end+start)/2;
    if(hlavny[end].first==to) return end;
    if(hlavny[start].first==to) return start;


    if(hlavny[stred].first==to) return stred;
    else if(hlavny[stred].first>to) stred = binarySearch(hlavny,start,stred,to);
    else stred = binarySearch(hlavny,stred,end,to);
    return stred;
}


int main(){

    
int t;
cin>>t;
while(t>0){
t--;

int h,k;
int u=1;
int pocet=0;
int vysledok=0;
// set<string> mena;
// vector<int> hlavny;
// pair<int,> spojovac;
vector<pair<string,int>> hlavny;


cin>>h;
string m;
getline(cin,m);

for(int i=0;i<h;++i){
    string p;
    getline(cin,p);
    hlavny.push_back({p,0});

}
sort(hlavny.begin(),hlavny.end());

cin>>k;
string g;
getline(cin,g);

for(int i=0;i<k;++i){
    string p;
    getline(cin,p);
    int f = binarySearch(hlavny,0,hlavny.size()-1,p);
    if(hlavny[f].second == u) continue;
    hlavny[f].second++;
    pocet++;
    if(pocet>=h){
        vysledok++;
        u++;
        pocet=1;
        hlavny[f].second++;
    }
    


}
cout<<vysledok<<endl;
}
}