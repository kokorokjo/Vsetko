#include <bits/stdc++.h>
using namespace std;

vector <pair<int,int>> v(1,make_pair(-1,-1));

void prepis(int k){
    
    while (k>1){
        if(v[k/2].first == -1 || v[k/2].first>v[k].first){
            v[k/2].first = v[k].first;
        }
        if(v[k/2].second == -1 || v[k/2].second>v[k].second){
            v[k/2].second = v[k].second;
        }
        k = k/2;
    }
}

int findInBinTree(int max){
    int p = 1;
    int result=1000000000;
    while(p<v.size()){
        if(v[p*2+1].first!=-1 && v[p*2+1].first<=max){
            if(v[p*2].second<result&&v[p*2].second!=-1){
                result = v[p*2].second;
            }
            p = p*2+1;
            if(p*2>=v.size()){
                break;
            }
        }
        else if(v[p*2].first!=-1 && v[p*2].first<=max){
            p = p*2;
            if(p*2>=v.size()){
                break;
            }
        }
        else{
            if(result==1000000000){
                return -1;
            }
            else{
                return result+1;
            }
        }
    }
    if(v[p].first!=-1 && v[p].first<=max){
        if(v[p].second<result&&v[p].second!=-1){
            result = v[p].second;
        }
    }
    if(result==1000000000){
        return -1;
    }
    else{
        return result+1;
    }
}

int main() {
    int n,d,b;
    cin>>n>>d>>b;
    
    while(v.size() < n){
        v.resize(v.size()*2,make_pair(-1,-1));
    }
    v.resize(v.size()*2,make_pair(-1,-1));
    for(int i=v.size()-n;i<v.size();i++){
        cin>>v[i].first;
        cin>>v[i].second;
    }
    for(int i=v.size()-1;i>=v.size()-n;i--){
        if(i==v.size()-1){
            if(v[i].first + v[i].second >= d){
                v[i].second = 1;
                prepis(i);
            }
        }
        else{
             if(v[i].first + v[i].second >= d){
                v[i].second = 1;
                prepis(i);
            }
            else{
                int p=findInBinTree(v[i].first + v[i].second);
                v[i].second = p;
                if(p!=-1){
                    prepis(i);
                }
            }
        }
    }
    int result = findInBinTree(b);
    if(b>=d){
        cout<<0<<endl;
    }
    else if(result==-1){
        cout<<-1<<endl;
    }
    else{
        cout<<result-1<<endl;
    }
    
}