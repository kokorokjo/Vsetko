#include <bits/stdc++.h>
using namespace std;

void vypis (vector<int> pole){
for (auto i : pole)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    int n, p, pomocna, malo;
    cin >> n;
    vector<int> hlavny(n), vrcholy(0), doliny(0);
    bool uz = false;
    cin >> pomocna;
    p = pomocna;
    hlavny[0]=0;
    hlavny[1] = pomocna;
    for (int i = 2; i < n+1; i++)
    {
        cin >> pomocna;
        hlavny[i] = pomocna;
        if (hlavny[i] > p)
        {
            p = hlavny[i];
            if (hlavny[i] < malo)
            {
                malo = p;
            }
        }
        else if (hlavny[i] == p)
        {
        }
        else if(hlavny[i]<p && hlavny[i-2]<p)
        {
            if (uz == true)
            {
                doliny.push_back(malo);
            }
            vrcholy.push_back(p);
            p= hlavny[i];
            uz = true;
            malo = hlavny[i];
        }
    }
    vypis(doliny);
    vypis(vrcholy);
    vypis(hlavny);

    return 0;
}