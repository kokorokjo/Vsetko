#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<vector<long long>> hlavny;
vector<long long> food;
vector<unordered_map<long long,long long>*> sandwich;
long long vysledok = 0;

void dfs(long long i,long long parent = -1){
    long long largest = -1;
    vector<long long> children;
    // cout<<i<<endl;
    for(auto j:hlavny[i]){
        if(j!=parent){
            children.push_back(j);
            dfs(j,i);
            if(largest==-1||sandwich[j]->size()>sandwich[largest]->size()){
                largest = j;
            }
        }
    }

    if(largest==-1){
        sandwich[i] = new unordered_map<long long,long long>();
    }
    else{
        sandwich[i] = sandwich[largest];
    }
    if(sandwich[i]->find(food[i])!=sandwich[i]->end()){
        vysledok+=sandwich[i]->at(food[i]);
        long long pocet = sandwich[i]->at(food[i])-1;
        vysledok += (pocet+1)*pocet/2;
        // cout<<pocet<<"_"<<vysledok<<"_"<<i<<endl;
    }
    for(auto child:children){
        if(child==largest)continue;
        for(auto x:*sandwich[child]){
            if(x.first==food[i]){
                vysledok+=x.second;
                long long pocet = x.second-1;
                vysledok += (pocet+1)*pocet/2;
                // cout<<pocet<<"-"<<vysledok<<"-"<<i<<endl;

            }
            if(sandwich[i]->find(x.first)==sandwich[i]->end()){
                sandwich[i]->insert(make_pair(x.first,x.second));
            }
            else{
                sandwich[i]->at(x.first)+=x.second;
            }
        }
    }
    if(sandwich[i]->find(food[i])!=sandwich[i]->end()){
        // long long pocet = sandwich[i]->at(food[i]);
        // vysledok += (pocet+1)*pocet/2;
        // cout<<pocet<<" "<<vysledok<<" "<<i<<endl;
        sandwich[i]->at(food[i])=1;
        // cout<<"f:"<<food[i]<<" "<<i<<endl;
    }
    else{
        sandwich[i]->insert(make_pair(food[i],1));
        // cout<<"f:"<<food[i]<<" "<<i<<endl;

    }

    if(parent==-1){
        // cout<<vysledok<<endl;
        for(auto x:*sandwich[i]){
            long long pocet = x.second-1;
            vysledok += (pocet+1)*pocet/2;
            // cout<<" "<<pocet<<" "<<vysledok<<" "<<x.first<<endl;
        }
    }

}


int main(){
    long long n;
    cin >> n;
    hlavny.resize(n);
    sandwich.resize(n,NULL);


    for(long long i=0;i<n;i++){
        long long p;
        cin >> p;
        food.push_back(p);
    }
    for(long long i=0;i<n-1;i++){
        long long a,b;
        cin >> a >> b;
        a--;
        b--;
        hlavny[a].push_back(b);
        hlavny[b].push_back(a);
    }
    //nacitanie

    dfs(0,-1);
    cout<<vysledok<<endl;

}