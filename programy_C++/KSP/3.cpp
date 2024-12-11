#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    long long n,t,p;
    cin>>n>>t>>p;
    long long pred=0;
    long long sucet=0;
    for(long long i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        if(a<=b*t){
            p--;
            sucet+=pred;
        }
        else{
            pred++;
        }
        if(p==0){
            break;
        }
    }
    if(p!=0){
        cout<<-1<<endl;
        return 0;
    }
    cout<<sucet<<endl;
    
}