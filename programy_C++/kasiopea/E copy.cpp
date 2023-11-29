#include <bits/stdc++.h>
using namespace std;

bool nieco=false;
bool koniec=false;

int BinarySearch(vector<string> v, string s){
    int l=0;
    int r=v.size()-1;
    while(l<=r){
        int m=(l+r)/2;
        if(v[m]==s) return m;
        else if(v[m]>s) r=m-1;
        else l=m+1;
    }
    return -1;
}

void rekurzia(string hlavny, vector<string> v, vector<string> &vysledok,vector<string> pomocny,string s, int index, int najvacsi){
    
    for(int i=index+s.size();i<hlavny.size();i++){
        // cout<<i<<" ";
        if(koniec) break;
        s+=hlavny[i];
        cout<<s.size()<<" ";
        if(s.size()>najvacsi) break;
        
        int k=BinarySearch(v,s);
        if(k==-1) continue;
            if(s==v[k]){
                
                s+=hlavny[i+1];
                for(int f=k+1;f<v.size();f++){
                    if(v[f].size()>=s.size()){
                        if(v[f].substr(0,s.size()-1)==s.substr(0,s.size()-1)){
                            if(v[f][s.size()-1]==s[s.size()-1]){
                                nieco=true;
                                break;
                            }
                            else{
                                nieco=false;
                                break;
                            }
                            
                        }

                    }
                    else{
                        nieco=false;
                        break;
                    }
                }
                if(nieco){
                    string s1=s;
                    s=s.substr(0,s.size()-1);
                    cout<<endl;
                    rekurzia(hlavny, v, vysledok, pomocny, s,index, najvacsi);
                    cout<<endl;
                    s=s1;
                }
                s=s.substr(0,s.size()-1);
                pomocny.push_back(s);
                // cout<<s<<" ";
                index+=s.size();
                s="";
                
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
    cout<<endl<<"index"<<index<<" "<<pomocny.size()<<endl;

    

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