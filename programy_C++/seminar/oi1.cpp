#include <bits/stdc++.h>    

using namespace std;

int main(){
int n,k,p;
cin>>n>>k>>p;
vector<vector<int>> v(n);
vector<int> v2(n,0);
vector<bool> bol(n,false),spojene(n,false);
queue<int> q;
vector<pair<int,int>> hrany;
int min=0,neviem=0;
vector<int> spol;

for(int i=0;i<p;i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v2[a]++;
    v[b].push_back(a);
    v2[b]++;
}
spojene[0]=true;
spol.push_back(0);
bol[0]=true;
q.push(0);

while(true){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++){
            if(!bol[v[x][i]]){
                bol[v[x][i]]=true;
                spojene[v[x][i]]=true;
                spol.push_back(v[x][i]);
                q.push(v[x][i]);
            }
        }
    }



    bool nieje=false;
    for(int i=min;i<n;i++){
        bool suhlas=false;
        if(!spojene[i]&&v2[i]<k){

            // for(int j=0;j<n;j++){
            //     if(spojene[j]&&v2[j]<k){
            //         v[j].push_back(i);
            //         v2[j]++;
            //         v2[i]++;
            //         hrany.push_back({j,i});
            //         suhlas=true;
            //         break;
            //     }
                
            // }
            for(int j=neviem;j<spol.size();j++){
                if(v2[spol[j]]<k){
                    v[spol[j]].push_back(i);
                    v2[spol[j]]++;
                    v2[i]++;
                    hrany.push_back({spol[j],i});
                    suhlas=true;
                    neviem=j;
                    break;
                }
            }
            if(!suhlas){
                cout<<-1<<endl;
                return 0;
            }
            q.push(i);
            spojene[i]=true;
            spol.push_back(i);
            bol[i]=true;
            nieje=true;
            
            break;
        }
        min=i;
    }
    if(!nieje){
        break;
    }

}
// cout<<"neviem"<<endl;
for(int i=0;i<n;i++){
    if(!spojene[i]){
        cout<<-1<<endl;
        return 0;
    }
}
for(int i=0;i<n;i++){
    if(v2[i]>k){
        cout<<-1<<endl;
        return 0;
    }
}
cout<<hrany.size()<<endl;
for(int i=0;i<hrany.size();i++){
    cout<<hrany[i].first<<" "<<hrany[i].second<<endl;
}


}