#include <bits/stdc++.h>
using namespace std;

bool nieco=false;
bool koniec=false;

void rekurzia(string hlavny, vector<string> v, vector<string> &vysledok,vector<string> pomocny,string s, int index, int najvacsi){
    
    for(int i=index+s.size();i<hlavny.size();i++){
        if(koniec) break;
        s+=hlavny[i];
        if(s.size()>najvacsi) break;
        for(int k=0;k<v.size();k++){
            if(s==v[k]){
                
                s+=hlavny[i+1];
                for(int f=0;f<v[k+1].size();f++){
                    nieco=true;
                    if(v[k+1][f]==s[f]) {
                        if(f==s.size()-1){
                        nieco=true;
                        break;
                    }
                        continue;
                    }
                    else {
                        nieco=false;
                        break;
                    };
                    
                }
                if(nieco){
                    string s1=s;
                    s=s.substr(0,s.size()-1);
                    rekurzia(hlavny, v, vysledok, pomocny, s,index, najvacsi);
                    s=s1;
                }
                s=s.substr(0,s.size()-1);
                pomocny.push_back(s);
                index+=s.size();
                s="";
                
            }
        }
        
        
        
    
    }
    if(!koniec){
    if(index==hlavny.size()){
        for(int i=0;i<pomocny.size();i++){
            vysledok.push_back(pomocny[i]);
        }
        koniec=true;
    }
    }
    

}

int main(){
    int t;
    ifstream MyReadFile("E-tezky (4).txt");
    ofstream MyFile("E-vysledok.txt");
    MyReadFile >> t;

    for(int all=0; all<t; all++){
        int n;
        MyReadFile >> n;
        string hlavny;
        MyReadFile >> hlavny;
        vector<string> v;
        int najvacsi=0;
        for(int i=0; i<n; i++){
            string s;
            MyReadFile >> s;
            v.push_back(s);
            if(s.size()>najvacsi) najvacsi=s.size();
        }
        sort(v.begin(), v.end());
        v.push_back("0");
        vector<string> vysledok;
        rekurzia(hlavny, v, vysledok, {}, "",0,najvacsi);
        
        if(vysledok.size()==0) MyFile << "NE"<< endl;
        else MyFile << "ANO" << endl;
        for(int i=0; i<vysledok.size(); i++){
            MyFile << vysledok[i];
            if(i!=vysledok.size()-1) MyFile << " ";
            else MyFile << endl;
        }

        nieco=false;
        koniec=false;
        cout<<all<<endl;
    }
    MyReadFile.close();
    MyFile.close();
    cout<<"hotovo"<<endl;
}