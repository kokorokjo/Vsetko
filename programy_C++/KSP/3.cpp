#include <bits/stdc++.h>
using namespace std;



int main() {
    vector<int> v;
    int a = 4, b = 7;
    int pocet=0;
    int p;
    cin>>p;
    for(int i=0;i<p;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            // cout<<v[i]<<" "<<v[j]<<endl;
            a=v[i];
            b=v[j];
        
       

    if((a&b)>(a^b)){
        pocet++;
    
        }
 
   
    }

    }
     cout<<pocet<<endl;
    return 0;
}