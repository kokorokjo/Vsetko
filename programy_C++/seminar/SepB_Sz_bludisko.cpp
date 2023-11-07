#include <bits/stdc++.h>

using namespace std;

int main(){
    bool ano=false;
    int r,s;
    vector<vector<char>> v;
    cin>>r>>s;
    for(int i=0;i<r;i++){
        vector<char> v2;
        for(int j=0;j<s;j++){
            char c;
            cin>>c;
            v2.push_back(c);
        }
        v.push_back(v2);
        
    }
    pair<int,int> start;
    for(int i=0;i<r;i++){
        for(int j=0;j<s;j++){
            cout<<v[i][j];
            if(v[i][j]=='S'){
                start.first=i;
                start.second=j;
            }
        }
        cout<<endl;
    }
    cout<<endl;
    //  for(int i=0;i<s;i++){
    //     for(int m=r-1;m>=0;m--){
    //         cout<<v[m][i];
    //     }
    //     cout<<endl;
    //  }
    int pomocna=0;
        if(v[start.first+1][start.second]=='.'){
            pomocna++;
        }
        if(v[start.first-1][start.second]=='.'){
            pomocna++;
        }
        if(v[start.first][start.second+1]=='.'){
            pomocna++;
        }
        if(v[start.first][start.second-1]=='.'){
            pomocna++;
        }
    cout<<"Pocet policok na ktore mozeme ist zo startu je :"<<pomocna<<endl;

    queue<pair<int,pair<int,int>>> q;
    q.push({0,{start.first,start.second}});
    vector<vector<bool>> visited(r,vector<bool>(s,false));
    visited[start.first][start.second]=true;
    while(!q.empty()){
        pair<int,pair<int,int>> p = q.front();
        q.pop();
        int x = p.second.first;
        int y = p.second.second;
        int dlazka = p.first;
        if(v[x][y]=='C'){
            cout<<"Najkratsia cesta je "<<dlazka<<endl;
            ano=true;
            break;
        }
        if(v[x+1][y]!='#' && !visited[x+1][y]){
            q.push({(dlazka+1),{x+1,y}});
            visited[x+1][y]=true;
        }
        if(v[x-1][y]!='#' && !visited[x-1][y]){
            q.push({(dlazka+1),{x-1,y}});
            visited[x-1][y]=true;
        }
        if(v[x][y+1]!='#' && !visited[x][y+1]){
            q.push({(dlazka+1),{x,y+1}});
            visited[x][y+1]=true;
        }
        if(v[x][y-1]!='#' && !visited[x][y-1]){
            q.push({(dlazka+1),{x,y-1}});
            visited[x][y-1]=true;
        }
    }
    if(!ano)

    cout<<"neni cesta"<<endl;
    queue<pair<int,pair<int,int>>> q2;
    q2.push({0,{start.first,start.second}});
    vector<vector<bool>> visited2(r,vector<bool>(s,false));
    visited2[start.first][start.second]=true;
    vector<vector<int>> idk(r,vector<int>(s,0));
    while(!q2.empty()){
        pair<int,pair<int,int>> p2 = q2.front();
        q2.pop();
        int x = p2.second.first;
        int y = p2.second.second;
        int dlazka = p2.first;
        if(v[x][y]=='C'){
            cout<<"Najkratsia cesta je "<<dlazka<<endl;
            for(int i=0;i<r;i++){
                for(int j=0;j<s;j++){
                    cout<<idk[i][j]<<" ";
                }
                cout<<endl;
            }
            return 0;
            break;
        }
        if(v[x+1][y]!='#' && !visited2[x+1][y]){
           
            for(int i=x+1;i<r;i++){
                if(v[i][y]=='#'||visited2[i][y]){
                    break;
                }
                q2.push({(dlazka+1),{i,y}});
                idk[i][y]=dlazka+1;
                visited2[i][y]=true;
            }
        }
        if(v[x-1][y]!='#' && !visited2[x-1][y]){
            for(int i=x-1;i>=0;i--){
                if(v[i][y]=='#' || visited2[i][y]){
                    break;
                }
                q2.push({(dlazka+1),{i,y}});
                idk[i][y]=dlazka+1;
                visited2[i][y]=true;
            }
        }
        if(v[x][y+1]!='#' && !visited2[x][y+1]){
            for(int i=y+1;i<s;i++){
                if(v[x][i]=='#' || visited2[x][i]){
                    break;
                }
                q2.push({(dlazka+1),{x,i}});
                idk[x][i]=dlazka+1;
                visited2[x][i]=true;
            }
        }
        if(v[x][y-1]!='#' && !visited2[x][y-1]){
            for(int i=y-1;i>=0;i--){
                if(v[x][i]=='#' || visited2[x][i]){
                    break;
                }
                q2.push({(dlazka+1),{x,i}});
                idk[x][i]=dlazka+1;
                visited2[x][i]=true;
            }
        }

    }
    cout<<"neni cesta"<<endl;
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<s;j++){
    //         cout<<idk[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}