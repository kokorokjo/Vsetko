#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long sucet=0;
    vector<int> v(n);
    int min,max;
    for(int i=0;i<n;++i) cin>>v[i];
    for(int i=0;i<n;i++){
        
        for(int j=i+1;j<n;j++){
            if(j==i+1){
                if(v[i]>v[j]){
                min=v[j];
                max=v[i];
            }
            else{
                min=v[i];
                max=v[j];
            }

            }
            else{
                if(v[j]<min) min=v[j];
                if(v[j]>max) max=v[j];
            }
            sucet+=max-min;
            


        }
    }
    cout<<sucet<<endl;
    return 0;

}