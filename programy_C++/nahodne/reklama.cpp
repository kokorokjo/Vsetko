#include <bits/stdc++.h>
using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}
int main(){
    int n,w,h;
    cin >> n >> w >> h;
    int maxh = 0;
    vector<pair<int,int>> maxw;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        maxw.push_back(make_pair(a,b));
    }
    sort(maxw.begin(),maxw.end(),sortbysec);
    /*for(int i=0;i<n;i++){
        cout<<maxw[i].first<<" "<<maxw[i].second<<endl;
    }*/
    vector<int> hlavny;
    int pomocne=0;
    for(int i=0;i<maxw.size();i++){
        if(maxw[i].second==pomocne){
            hlavny[hlavny.size()-1]+=maxw[i].first;
        }
        else{
            maxh+=maxw[i].second;
            hlavny.push_back(maxw[i].first);
            pomocne=maxw[i].second;
        }
    }
    /*for(int i=0;i<hlavny.size();i++){
        cout<<hlavny[i]<<endl;
    }*/
    sort(hlavny.begin(),hlavny.end());
    int neviem,vysledok;
    neviem=hlavny[hlavny.size()-1];
    //cout<<neviem<<" "<<maxh<<endl;
    if(neviem>w&&maxh>h){
        float idk=(float)w/(float)neviem;
        float asi=(float)h/(float)maxh;
        cout<<max(asi,idk)<<endl;
        return 0;
    }
    if(neviem>w){
        cout<<(float)w/(float)neviem<<endl;
        return 0;
    }
    if(maxh>h){
        cout<<(float)h/(float)maxh<<endl;
        return 0;
    }
    if((float)h/(float)maxh<(float)w/(float)neviem) cout<<(float)h/(float)maxh<<endl;
    else cout<<(float)w/(float)neviem<<endl;
    return 0;

}