#include <bits/stdc++.h>
using namespace std;
 

int minCoins(vector<int> coins, int n, int V,vector<vector<int>> &store)
{
    vector<int> pocetMince(V + 1,INT_MAX);
 
    pocetMince[0] = 0;
 
    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++){

            if (coins[j] <= i) {

                int pomocna = pocetMince[i - coins[j]];
                if (pomocna != INT_MAX && pomocna + 1 < pocetMince[i]){

                    pocetMince[i] = pomocna + 1;
                    vector<int> pomocny;
                    pomocny=store[i-coins[j]];
                    pomocny.push_back(coins[j]);
                    store[i]=pomocny;

                }
            }
        }
    }
 
    if (pocetMince[V] == INT_MAX)
        return -1;
 
    return pocetMince[V];
}
 

 
    
 
int main()
{
    string s;
    int sum;
    string token;
    vector<int> coins;
    int n;
    vector<vector<int>> store;


    getline(cin,s);
    istringstream ss(s);
    while(getline(ss, token, ' ')) {
        coins.push_back(stoi(token));
    }


    n = coins.size();
    cin >> sum; 
    store.resize(sum+1);

    cout<<minCoins(coins, n, sum,store)<<endl;


    for(int i=0;i<store[sum].size();i++){
        cout<<store[sum][i];
        if(i!=store[sum].size()-1)
            cout<<" ";
        else
            cout<<endl;
        
    }

 
    return 0;
}