#include <bits/stdc++.h>
using namespace std;

pair<int,int> smery(pair<int,int> pozicia,int smer){
    if(smer==0){
        return make_pair(pozicia.first+1,pozicia.second);
    }
    if(smer==1){
        return make_pair(pozicia.first+1,pozicia.second+1);
    }
    if(smer==2){
        return make_pair(pozicia.first,pozicia.second+1);
    }
    if(smer==3){
        return make_pair(pozicia.first-1,pozicia.second+1);
    }
    if(smer==4){
        return make_pair(pozicia.first-1,pozicia.second);
    }
    if(smer==5){
        return make_pair(pozicia.first-1,pozicia.second-1);
    }
    if(smer==6){
        return make_pair(pozicia.first,pozicia.second-1);
    }
    if(smer==7){
        return make_pair(pozicia.first+1,pozicia.second-1);
    }
}

int main(){
    int t;
    ifstream in("Ginput.txt");
    ofstream out("Goutput.txt");
    in >> t;
    for(int all=0;all<t;all++){
        int n,m,k;
        in >>n>>m>>k;
        vector<vector<int>> hlavny(n+2,vector<int>(m+2,-1));
        vector<vector<pair<pair<int,int>>>> vzdialenost(n+2,vector<pair<int,int>>(m+2,make_pair(-1,-1)));
        pair<int,int> start,ciel;
        vector<vector<int>> visited(n+2,vector<int>(m+2,0));
        in >> start.first >> start.second >> ciel.first >> ciel.second;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                in >> hlavny[i][j];
            }
        }
        priority_queue<pair<int,pair<int,int>>> q;
        while(!q.empty()){
            pair<int,pair<int,int>> aktualny = q.top();
            q.pop();
            if(visited[aktualny.second.first][aktualny.second.second]==1){
                continue;
            }
            for(int i=0;i<8;i++){
                pair<int,int> smer = smery(aktualny.second,i);
                if(hlavny[smer.first][smer.second]==-1){
                    continue;
                }
                if(hlavny[smer.first][smer.second]-hlavny[aktualny.second.first][aktualny.second.second]<vzdialenost)

            }
        }
    }
}