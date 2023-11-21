#include <bits/stdc++.h>
using namespace std;


int main(){

    int n,m;
    cin >> n >> m;
    int pocet = 0;
    vector<vector<char>> v(n+2, vector<char>(m+2, '.'));

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            cin >> v[i][j];
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(v[i][j] == '/'){
                if(v[i+1][j+1]=='/' && v[i+1][j] =='\\'&& v[i][j+1] =='\\'){
                    pocet++;
                }
            }
        }
        
    }
    cout << pocet << endl;
}