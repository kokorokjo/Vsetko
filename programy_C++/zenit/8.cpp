#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m,l;
    cin >> n >> m >> l;
    vector<vector<int>> a(n+2,vector<int>(m+2,0));
    vector<pair<int,int>> b(n*m+1);
    vector<vector<bool>> c(n+2,vector<bool>(m+2,false));
    int pocitadlo=1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            b[pocitadlo].first=i;
            b[pocitadlo].second=j;
            a[i][j]=pocitadlo;
            pocitadlo++;
        }
    }
    int pozicia=0;
    cin>>pozicia;
    c[b[pozicia].first][b[pozicia].second]=true;
    for(int i=1;i<l;i++){
        int asi;
        cin >> asi;
        if(c[b[asi].first][b[asi].second]==true){
            cout<<"Nie"<<endl;
            return 0;
        }
        c[b[asi].first][b[asi].second]=true;



        if(b[asi].first==b[pozicia].first){
            if(b[asi].first>b[pozicia].first){
                for(int j=b[pozicia].second;j<=b[asi].second;j++){
                    if(c[b[pozicia].first][j]!=true){
                        cout<<"Nie"<<endl;
                        return 0;
                    }
                }
                pozicia=asi;
                continue;
            }
            else{
                for(int j=b[asi].second;j<=b[pozicia].second;j++){
                    if(c[b[pozicia].first][j]!=true){
                        cout<<"Nie"<<endl;
                        return 0;
                    }
                }
                pozicia=asi;
                continue;
            }
        }
        else if(b[asi].second==b[pozicia].second){
            if(b[asi].first>b[pozicia].first){
                for(int j=b[pozicia].first;j<=b[asi].first;j++){
                    if(c[j][b[pozicia].second]!=true){
                        cout<<"Nie"<<endl;
                        return 0;
                    }
                }
                pozicia=asi;
                continue;
            }
            else{
                for(int j=b[asi].first;j<=b[pozicia].first;j++){
                    if(c[j][b[pozicia].second]!=true){
                        cout<<"Nie"<<endl;
                        return 0;
                    }
                }
                pozicia=asi;
                continue;
            }
        }
        else if(b[asi].first>b[pozicia].first){
            if(b[asi].second>b[pozicia].second){
                for(int j=b[pozicia].first+1;j<=b[asi].first;j++){
                    if(c[j][b[].second]!=true){
                        cout<<"Nie"<<endl;
                        return 0;
                    }
                }

            }
            else{

            }
        }









        cout<<"Nie"<<endl;
        return 0;
        
    }
    cout<<"Ano"<<endl;
    return 0;
}