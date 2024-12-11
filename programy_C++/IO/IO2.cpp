#include <bits/stdc++.h>
#define INF 99999999999.0

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;



int main() {
    int n;
    cin >> n;
    vector<long long> v(n+1, 10000);
    long long top = 0;
    vector<vector<int>> dp(n, vector<int>(3, 0));
    vector<int> test(n+1);
    for(int i;i<n;i++){
        char p;
        cin >> p;
        if(p=='N'){
            dp[i][0] = 0;
        }
        else{
            dp[i][0] = 1;
        }
        cin >> dp[i][1] >> dp[i][2];
    }

    for(int i=0;i<n;i++){
        if(dp[i][0]==0){
            //nakup
            int typ = dp[i][1],cena = dp[i][2];
            if(v[typ] > cena-top){
                v[typ] = cena-top;
            }
        }
        else{
            //predaj
            int typ = dp[i][1],cena = dp[i][2];
            if(top<cena-v[typ]){
                top = cena-v[typ];
            }
            else{
                // cout<<cena-v[typ]<<endl;
            }
        }
        test[i] = top;
    }
    cout<<top<<endl;

}
