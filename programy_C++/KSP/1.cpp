#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    int s,v;
    cin >> s >> v;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        int x;
        cin >> x;
    }
    
    int max = 1;
    int last = a[0];
    for(int i=0;i<n;i++){
        if(s+last>a[i]){
            
            continue;
        }
        max++;
        last=a[i];
        
    }
    cout<<max<<endl;

    
}
