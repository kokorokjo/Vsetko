#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for(int i=0; i<n; i++){
        if(a[i]==b[i]||a[i]==b[i]-1){
            continue;
        }
        else{
            cout << "Neda sa" << endl;
            return 0;
        }
    }
    cout<<"Jednoduche"<<endl;
}