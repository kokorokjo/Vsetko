#include <bits/stdc++.h>
using namespace std;

struct point{
    int x,y;
};




int main(){

    int n;
    int s,v;
    cin >> n >> s >> v;
    vector<point> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].x >> a[i].y;
    }
    vector<vector<int>> inside(n);
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(a[i].x>=a[j].x && a[i].x+s<a[j].x){
                inside[i].push_back(j);
                inside[j].push_back(i);
            }
        }
    }
    

}