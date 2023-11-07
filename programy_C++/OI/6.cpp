#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> ano(n,-1),otec(n,-1),listy,spracovane(n,0),dieta2(n,0),halo(n,0),halo2=halo,ano2=ano;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='M'){
            ano[i]=1;
        }
    }
    vector<vector<int> > vedlajsi(n);
    queue<int> nieco;
    bool bol=false;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        vedlajsi[a].push_back(b);
        vedlajsi[b].push_back(a);
    }

    for(int i=0;i<n;i++){
        ano2=ano;
        halo2=halo;
        nieco.push(i);
        while(nieco.empty()==false){
            int idk=nieco.front();
            nieco.pop();
        for(int k=0;k<vedlajsi[idk].size();k++){
            if(vedlajsi[idk][k]==otec[idk])continue;
            otec[vedlajsi[idk][k]]=idk;
            dieta2[idk]++;
            bol=true;
            nieco.push(vedlajsi[idk][k]);
        }
        if(bol==false){
            listy.push_back(idk);
            
        }
        bol=false;
        }
        for(int k=0;k<n;k++){
      //      cout<<otec[k]<<" ";
        }
      //  cout<<endl;
        for(int k=0;k<listy.size();k++){
       //     cout<<listy[k]<<" ";
            nieco.push(listy[k]);
        }
        listy.clear();
      //  cout<<endl;
        while(nieco.size()!=0){
            int idk=nieco.front();
            nieco.pop();
            if(halo2[idk]==1)continue;
            if(spracovane[idk]==dieta2[idk]){
                halo2[idk]=1;
        if(ano2[idk]>=0){
            ano2[otec[idk]]+=ano2[idk];}
            spracovane[otec[idk]]++;
            if(otec[idk]!=-1)
            nieco.push(otec[idk]);
            }

        }
        if(i+1==n){
            cout<<ano2[i]<<endl;
            return 0;
        }
       for(int k=0;k<n;k++){
            otec[k]=-1;
            spracovane[k]=0;
            dieta2[k]=0;
        }

        cout<<ano2[i]<<endl;

               
    }

return 0;
}