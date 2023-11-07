#include <bits/stdc++.h>    

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> gulocky(1);
    vector<pair<int,int>> vysledky(0);
    vector<int> poradie(1000001);
    queue<int> fronta;
    while(gulocky.size()<=1000000){
        gulocky.resize(gulocky.size()*2);
    }
    for(int i=1;i<1000001;i++){
        gulocky[i].second=i;
        poradie[i]=i;
    }
    for(int i=0;i<n;i++){
        if(fronta.size()==k){
            int a=fronta.front();
            fronta.pop();
            gulocky[poradie[a]].first--;
            while(poradie[a]*2<1000001){
                if(gulocky[poradie[a]].first<gulocky[poradie[a]*2].first||gulocky[poradie[a]].first<gulocky[(poradie[a]*2)+1].first){
                    if(gulocky[poradie[a]].first<gulocky[(poradie[a]*2)].first){
                        int b=gulocky[poradie[a]*2].second;
                        swap(gulocky[poradie[a]],gulocky[poradie[a]*2]);
                        swap(poradie[a],poradie[b]);
                        
                        
                    }else{
                        int b=gulocky[(poradie[a]*2)+1].second;
                        swap(gulocky[poradie[a]],gulocky[(poradie[a]*2)+1]);
                        swap(poradie[a],poradie[b]);
                        
                        
                    }
                    
                }
                else{
                    break;
                }
            }
        }
        int a;
        cin >> a;
        gulocky[poradie[a]].first++;
        fronta.push(a);
        while(poradie[a]>1){
            if(gulocky[poradie[a]].first>gulocky[poradie[a]/2].first){
                int b=gulocky[poradie[a]/2].second;
                swap(gulocky[poradie[a]],gulocky[poradie[a]/2]);
                swap(poradie[a],poradie[b]);
                
                
            }
            else{
                break;
            }
        }
        vysledky.push_back(gulocky[1]);
    }
    for(int i=0;i<vysledky.size();i++){
        cout << vysledky[i].second << " " << vysledky[i].first << endl;
    }

}