#include <iostream>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    queue<pair<int, int>> steny, tecenie;
    cin >> n >> m;
    m*=2;
    n*=2;
    string f;
    getline(cin,f);
    vector<vector<char>> v(n + 1, vector<char>(m + 1));
    vector<vector<bool>> bol(n + 1, vector<bool>(m + 1, false));
    vector<int> pocty;
    pocty.push_back(0);

    for (int i = 0; i <= n; i++)

    {
        string s;
        getline(cin,s);
        for (int j = 0; j <= m; j++)
        {
            v[i][j]=s[j];
            if (v[i][j] == ' ')
            {
                tecenie.push(make_pair(j, i));
            }
            if (v[i][j] == '|' || v[i][j] == '-')
            {
                steny.push(make_pair(j, i));
            }
            if (v[i][j] == '#' || v[i][j] == '|' || v[i][j] == '-' || v[i][j] == '+')
            {
                bol[i][j] = true;
            }
        }
    }
    // for(auto i : bol){
    //     for(auto j : i){
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    int kolkate = 0;
    while (!tecenie.empty())
    {
        int x = tecenie.front().first;
        int y = tecenie.front().second;
        tecenie.pop();
        if (bol[y][x] == true)
        {
            continue;
        }
        int pocitadlo = 0;
        queue<pair<int, int>> q;
        kolkate++;
        q.push(make_pair(x, y));
        bol[y][x] = true;
        while (!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            q.pop();
            if (v[y][x] == ' ')
            {
                pocitadlo++;
            }
            v[y][x] = kolkate + '0';

            if (bol[y + 1][x] == false)
            {
                bol[y + 1][x] = true;
                q.push(make_pair(x , y+1));
                
            }
            if (bol[y - 1][x] == false)
            {
                bol[y - 1][x] = true;
                q.push(make_pair(x , y-1));
            }
            if (bol[y][x + 1] == false)
            {
                bol[y][x + 1] = true;
                q.push(make_pair(x+1, y ));
            }
            if (bol[y][x - 1] == false)
            {
                bol[y][x - 1] = true;
                q.push(make_pair(x-1, y));
            }
            if(q.empty()){
                pocty.push_back(pocitadlo);
            }
        }
    //     for(auto i : v){
    //     for(auto j : i){
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    }
    // cout << kolkate << endl;
    // for(auto i : v){
    //     for(auto j : i){
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    // for(auto i : bol){
    //     for(auto j : i){
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    // for(auto i:pocty){
    //     cout << i << " ";
    // }
int max = 0;
    while(!steny.empty()){
        int x = steny.front().first;
        int y = steny.front().second;
        steny.pop();
        if(v[y][x]=='|'){
            int a=0,b=0;
            int a1=0,b1=0;
            if(v[y][x-1]!='.'&&v[y][x-1]!='#'&&v[y][x-1]!='+'){
                a1=v[y][x-1]-'0';
                a=pocty[a1];
            }
            if(v[y][x+1]!='.'&&v[y][x+1]!='#'&&v[y][x+1]!='+'){
                b1=v[y][x+1]-'0';
                b=pocty[b1];
            }
            if(a+b>max&&a1!=b1){
                max=a+b;
            }
        }
        else{
            int a=0,b=0;
            int a1=0,b1=0;
            if(v[y-1][x]!='.'&&v[y-1][x]!='#'&&v[y-1][x]!='+'){
                a1=v[y-1][x]-'0';
                a=pocty[a1];
            }
            if(v[y+1][x]!='.'&&v[y+1][x]!='#'&&v[y+1][x]!='+'){
                b1=v[y+1][x]-'0';
                b=pocty[b1];
            }
            if(a+b>max&&a1!=b1){
                max=a+b;
            }

        }
        
    }
    // cout<<endl;
    cout << max<<endl;



    return 0;

}