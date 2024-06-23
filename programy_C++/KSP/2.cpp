#include <bits/stdc++.h>
#include <vector>
using namespace std;



int main(){
    int n;
    cin>>n;
    bool nula=false;
    vector<int> ostatne,kladne,zaporne,Vostatne,Vkladne,Vzaporne;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==0){
            ostatne.push_back(a);
        }
        else if(a<0){
            zaporne.push_back(a);
        }
        else if(a>0){
            kladne.push_back(a);
        }
    }
    if(zaporne.size()==1){
        Vzaporne.push_back(zaporne[0]);
        Vkladne=kladne;
        Vostatne=ostatne;

    }
    else if(zaporne.size()==2){
        Vzaporne.push_back(zaporne[0]);
        Vostatne.push_back(zaporne[1]);
        Vkladne=kladne;
        Vostatne=ostatne;
        

    }
    else if(zaporne.size()==3){
        Vzaporne.push_back(zaporne[0]);
        Vkladne.push_back(zaporne[1]);
        Vkladne.push_back(zaporne[2]);
        if(kladne.size()==1){
            Vzaporne.push_back(kladne[0]);

        }
        else if(kladne.size()==2){
            Vostatne.push_back(kladne[1]);
        }

    }
    else if(zaporne.size()==4){
        Vzaporne.push_back(zaporne[0]);
        Vkladne.push_back(zaporne[1]);
        Vkladne.push_back(zaporne[2]);
        Vostatne.push_back(zaporne[3]);
        if(kladne.size()==1){
            Vzaporne.push_back(kladne[0]);

        }

    }






    cout<<Vzaporne.size();
    for(int i=0;i<Vzaporne.size();i++){
        cout<<" "<<Vzaporne[i];
    }
    cout<<endl;
    cout<<Vkladne.size();
    for(int i=0;i<Vkladne.size();i++){
        cout<<" "<<Vkladne[i];
    }
    cout<<endl;
    cout<<Vostatne.size();
    for(int i=0;i<Vostatne.size();i++){
        cout<<" "<<Vostatne[i];
    }
    cout<<endl;

    



}