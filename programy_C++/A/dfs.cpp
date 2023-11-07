#include <bits/stdc++.h>

using namespace std;

int n;                         // pocet vrcholov
vector<vector<int> > sused(n); // zoznam susedov
vector<bool> cerveny(n);       // true, ak je dany vrchol zeleny

void dfs(int Z)
{
    cerveny[Z] = true;
    for(int i=0; i<sused[Z].size(); i++)
    {
        if(!cerveny[sused[Z][i]])
        {
            dfs(sused[Z][i]);
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int pocet;
        cin>>pocet;
        for(int j=0; j<pocet; j++)
        {
            int Sused;
            cin>>Sused;
            Sused--;
            sused[i].push_back(Sused);
        }
    }
    dfs(0);
    for(int i=0; i<n; i++)
    {
        if(!cerveny[i])
        {
            cout<<i+1<<endl;
        }
    }
    return 0;
}
