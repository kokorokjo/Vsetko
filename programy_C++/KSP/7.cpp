#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std; 

unordered_map<char, pair<int,int>> polynomy;
const int p = 31;
int m = 1e9 + 9;

void increaseAll(){
    for(int i=0;i<26;i++){
        char a='a'+i;
        if(polynomy.find(a)==polynomy.end()){
            continue;
        }
        polynomy[a].second=(polynomy[a].second*p)%m;
    }
}


int main(){
    string s,t;
    cin>>s>>t;
    int S = s.size(), T = t.size();
    int vysledok=0;
    int hash=0;
    queue<int> b;
    unordered_map<char, queue<int>> poradie;
    vector<pair<int,char>> zoradene;
    unordered_map<char,char> mam;
    int h=1;
    for(int i=0;i<S-1;i++){
        h = (h*p)% m;
    }//only first time
    int pocitadlo=-1;
    for(int i=0;i<S;i++){
        if(mam.find(s[i])==mam.end()){
            pocitadlo++;
            mam[s[i]]='a'+pocitadlo;
            char fold='a'+pocitadlo;
            hash=((hash*p)+fold)%m;
        }
        else{
            hash=((hash*p)+mam[s[i]])%m;
        }
        
    }//only first time

    for(int i=0;i<S-1;i++){
        char a;
        a=t[i];
        if(poradie.find(a)==poradie.end()){
            queue<int> q;
            poradie[a]=q;
        }
        increaseAll();
        if(polynomy.find(a)==polynomy.end()){
            polynomy[a]=make_pair(a,a);
        }
        else{
            polynomy[a].second=polynomy[a].second+=polynomy[a].first;
        }
        poradie[a].push(i);
    } // only first time



    for(int all=0;all+S<=T;all++){
        // pridanie
        char o;
        o=t[all+S-1];
        if(poradie.find(o)==poradie.end()){
            queue<int> q;
            poradie[o]=q;
        }
        increaseAll();
        if(polynomy.find(o)==polynomy.end()){
            polynomy[o]=make_pair(o,o);
        }
        else{
            polynomy[o].second=polynomy[o].second+=polynomy[o].first;
        }
        poradie[o].push(all+S-1);
    

        //24 for all characters
        for(int i=0;i<26;i++){
            char a='a'+i;
            if(poradie.find(a)==poradie.end()){
                continue;
            }
            if(poradie[a].size()!=0){
                zoradene.push_back(make_pair(poradie[a].front(),a));
            }
        }

        sort(zoradene.begin(),zoradene.end());
        int porovnavanie=0;
        for(int i=0;i<zoradene.size();i++){
            char a='a'+i;
            int cinitel=polynomy[zoradene[i].second].first;
            polynomy[zoradene[i].second].second=(polynomy[zoradene[i].second].second/cinitel*a)%m;
            polynomy[zoradene[i].second].first=a;
            porovnavanie+=polynomy[zoradene[i].second].second;
        }
        if(porovnavanie==hash){
            vysledok++;
            // cout<<all<<endl;
        }
        porovnavanie=0;
        //odstranovanie
        o=t[all];
        polynomy[o].second=(polynomy[o].second+m-(polynomy[o].first*h))%m;
        poradie[o].pop();
        zoradene.clear();


    }

    cout<<vysledok<<endl;
    return 0;
    

}