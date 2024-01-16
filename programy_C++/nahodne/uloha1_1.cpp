#include <bits/stdc++.h>
using namespace std;

void vypis(vector<char> &hlavny)
{
    for (int i=0; i<hlavny.size()-1; i++)
    {
        cout<<hlavny[i];
    }
    cout<<hlavny[hlavny.size()-1]<<endl;
}

int main()
{

    int n,k,sucet;
    cin>>n>>k;
    char maximum='A';
    int netusim=n-1;
    maximum=maximum+k-1;
    vector<char> hlavny(n,'A');
    sucet=k;
    for(int i=1; i<n; i++)
    {
        sucet*=k;
    }

   vypis(hlavny);
    for(int i=1; i<sucet; i++)
    {
        if(hlavny[netusim]==maximum){
            for(int k=netusim;k>=0;k--){
                if(hlavny[k]==maximum){
                    hlavny[k]='A';
                    continue;
                }
                else{
                    hlavny[k]++;
                    break;
                }
            }
        }
        else{
            hlavny[netusim]++;
        }
        vypis(hlavny);

    }



}