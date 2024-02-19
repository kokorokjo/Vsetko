#include <bits/stdc++.h>
using namespace std;

bool bin_search(vector<int> &hlavny,int neviem){
    int zaciatok=0;
    int koniec=hlavny.size();
    while(zaciatok+1!=koniec){
    int pomocna=(zaciatok+koniec)/2;
    if (hlavny[pomocna]>neviem)
        koniec=pomocna;
    else
            zaciatok=pomocna;
    }
    if(hlavny[zaciatok]==neviem)
    return true;
    else if(hlavny[koniec]==neviem)
        return true;
    else
    return false;
}

int main(){
   int n;
   cin>>n;
   vector<int> hlavny(n),vedlajsi;
   for(int i=0;i<n;i++){
    cin>>hlavny[i];
   }
   int q;
   cin>>q;
   for(int i=0;i<q;i++){
       int pomocna;
        cin>>pomocna;
    vedlajsi.push_back(pomocna);
   }
   for (int i=0;i<q;i++){
    int pomocna;
    pomocna=vedlajsi[i];
    if(bin_search(hlavny,pomocna))
        cout<<"A"<<endl;
    else if(bin_search(hlavny,pomocna-=pomocna*2))
        cout<<"A"<<endl;
    else
        cout<<"N"<<endl;

   }
}