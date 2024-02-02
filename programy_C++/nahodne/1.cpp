#include <iostream>
using namespace std;

<<<<<<< HEAD
bool is_prime(long long n) {
    if (n == 1) {
        return false;
=======

int main(){
    vector<pair<int,int>> v;
    vector<int> pozicie(1000000,-1);
    int n;
    cin >> n;
    vector<int> vysledok;

    for(int vsetko = 0; vsetko < n; vsetko++){
        string s;
        cin >> s;
        if(s=="INV"){
            vysledok.push_back(v[0].second);
        }
        else{
            int x;
            x = stoi(s);
            if(pozicie[x]!=-1){
            if(x>0)
            v[pozicie[x]].first++;
            else
            v[pozicie[x]].first--;
        }
        else{
            v.push_back(make_pair(1,x));
            pozicie[x] = v.size()-1;
        }
        while(pozicie[x]!=0){
            if(v[pozicie[x]].first>v[pozicie[x]/2].first){
                swap(v[pozicie[x]],v[pozicie[x]/2]);
                swap(pozicie[v[pozicie[x]].second],pozicie[v[pozicie[x]/2].second]);
            }
            else{
                break;
            }

        }
        while(true){
            if(pozicie[x]*2<v.size()){
                if(v[pozicie[x]].first<v[pozicie[x]*2].first){
                    swap(v[pozicie[x]],v[pozicie[x]*2]);
                    swap(pozicie[v[pozicie[x]].second],pozicie[v[pozicie[x]*2].second]);
                    continue;
                }
            }
            else if(pozicie[x]*2+1<v.size()){
             
                if(v[pozicie[x]].first<v[pozicie[x]*2+1].first){
                    swap(v[pozicie[x]],v[pozicie[x]*2+1]);
                    swap(pozicie[v[pozicie[x]].second],pozicie[v[pozicie[x]*2+1].second]);
                    continue;
                }
            }
            else{
                break;
            }
        }
            
            
        }

    }
    cout<<"vysldky"<<endl;
    for(int i = 0; i < vysledok.size(); i++){
        cout << vysledok[i] << endl;
>>>>>>> d56c00a484959d3a84d7e0444f52f0a6a106adce
    }

    int i = 2;

    while (i*i <= n) {
        
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }
   
    return true;
}

int main() {
    int t;
    cin >> t;
    for(int x=0; x<t; x++) {
        long long n;
        cin >> n;
        cout  << (is_prime(n) ? "ANO" : "NIE") << endl;
        
    }

    return 0;
}