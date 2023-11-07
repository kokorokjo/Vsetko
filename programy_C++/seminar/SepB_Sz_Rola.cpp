#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<string> v;
    cout<<"Pocet hráčov:";
    int pocet;
    cin>>pocet;
    cout<<"Napíšte postvy:";
    for(int i=0; i<pocet; i++){
        string s;
        cin >> s;
        for(int j=0;j<s.size();j++){
            if(s[j]==','){
                s.erase(s.begin()+j);
            }
            
        }
        if(s.size()==0){
                i--;
            }
            else{
                v.push_back(s);
            }
        
    }
    for(int i=0; i<pocet-1; i++){
        int j = rand() % (pocet-1);
        swap(v[i], v[j]);
    }
    char vstup,asi;
    int pomocna,pomocna2;
    string idk;
    vector<string> pomocny(pocet);
    while(true){
        cin>>vstup;
        switch (vstup)
        {
        case 'P': 
            cin>>pomocna;
            cout<<v[pomocna];
            break;
        case 'V':
            cin>>pomocna>>pomocna2;
            swap(v[pomocna],v[pomocna2]);
            break;
        case 'U':
            cin>>pomocna>>pomocna2;
            swap(v[pomocna],v[pomocna2]);
            cout<<v[pomocna];
            break;
        case 'X':
            cin>>pomocna;
            v.erase(v.begin()+pomocna);
            break;
        case '+':
            
            cin>>idk>>pomocna;
            v.insert(v.begin()+pomocna,idk);
            break;
        case 'Z':
            cin>>idk;
            for(int i=0;i<v.size();i++){
                if(v[i]==idk){
                    cout<<i;
                }
            }
            break;
        case 'I':
            cin>>pomocna>>asi;
            if(asi=='+'){
                if(pomocna==0){
                    for(int i=1;i<v.size()-1;i++){
                   pomocny[i+1]=v[i];
                    }
                    pomocny[1]=v[v.size()-1];
                    pomocny[0]=v[0];
                }
                else if(pomocna==v.size()-1){
                    for(int i=0;i<v.size()-2;i++){
                   pomocny[i+1]=v[i];
                    }
                    pomocny[0]=v[v.size()-2];
                    pomocny[v.size()-1]=v[v.size()-1];
                }
                else{
                    for(int i=0;i<v.size()-1;i++){
                        if(pomocna==i+1){
                            pomocny[i+2]=v[i];
                            pomocny[i+1]=v[i+1];
                            i++;
                        }
                        else{
                            pomocny[i+1]=v[i];
                        }
                    
                }
                pomocny[0]=v[v.size()-1];
                }
            }


            else{
                if(pomocna==0){
                    for(int i=1;i<v.size()-1;i++){
                   pomocny[i]=v[i+1];
                    }
                    pomocny[v.size()-1]=v[1];
                    pomocny[0]=v[0];
                }
                else if(pomocna==v.size()-1){
                    for(int i=0;i<v.size()-2;i++){
                   pomocny[i]=v[i+1];
                    }
                    pomocny[v.size()-2]=v[0];
                    pomocny[v.size()-1]=v[v.size()-1];
                }
                else{
                    for(int i=0;i<v.size()-1;i++){
                        if(pomocna==i+1){
                            pomocny[i]=v[i+2];
                            pomocny[i+1]=v[i+1];
                            i++;
                        }
                        else{
                            pomocny[i]=v[i+1];
                        }
                    
                }
                pomocny[v.size()-1]=v[0];
                }

            }
            v=pomocny;
            for(auto i:v){
                cout<<i<<" ";
            }
            break;
        }
    }
}