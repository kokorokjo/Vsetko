#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, ke, l, b = 0, pomocna, right = 0, left = 0, pright, poradie = 0, pleft, hodnota, p = 0;
    cin >> n >> k >> l;
    int hlavny[n];
    vector<int> postup(0);
    for (int i = 0; i < n; i++)
    {
        cin >> hlavny[i];
    }
    ke = hlavny[k - 1];
    for (int i = 0; i < n; i++)
    {
        if (hlavny[i] < ke)
        {
            left++;
        }
        if (hlavny[i] > ke)
        {
            right++;
        }
    }
    if (left >= k)
    {
        cout << "NIE" <<  endl;
        return 0;
    }
    if (right + k > n)
    {
        cout << "NIE" <<  endl;
        return 0;
    }
    right=0;
    left=0;
    while (poradie < k - 1)
    {

        if (hlavny[poradie] > ke)
        {
            pleft = poradie;
            pright = k - 2;
            if (pleft != pright)
            {
                postup.push_back(pleft + 1);
                postup.push_back(pright + 1);
                p = p + 2;
            }
            while (pleft < pright)
            {
                swap(hlavny[pleft], hlavny[pright]);
                pleft++;
                pright--;

            }
            swap(hlavny[k - 2], hlavny[k]);
            postup.push_back(k - 1);
            postup.push_back(k + 1);
            p = p + 2;
            pleft = k;
            pright = n - 1 - right;
            if (pright != pleft)
            {
                postup.push_back(pleft + 1);
                postup.push_back(pright + 1);
                p = p + 2;
            }
            while (pleft < pright)
            {

                swap(hlavny[pleft], hlavny[pright]);
                pright--;
                pleft++;
            }
            right++;
        }
        else
        {
            poradie++;
        }
    }

    for (int i = 0; i < k - 1; i++)
    {
        hodnota = hlavny[i];
        pomocna = i;
        for (int f = i; f < k - 1; f++)
        {
            if (hodnota > hlavny[f])
            {
                hodnota = hlavny[f];
                pomocna = f;
            }
        }
        pleft = i;
        pright = pomocna;
        if (pright != pleft)
        {
            postup.push_back(pleft + 1);
            postup.push_back(pright + 1);
            p = p + 2;
        }
        while (pleft < pright)
        {
            swap(hlavny[pleft], hlavny[pright]);
            pright--;
            pleft++;

        }
    }
    hodnota = hlavny[k];
    for (int i = k; i < n - 1; i++)
    {
        hodnota = hlavny[i];
        pomocna = i;
        for (int f = i; f < n; f++)
        {
            if (hodnota > hlavny[f])
            {
                hodnota = hlavny[f];
                pomocna = f;
            }

        }

        pleft = i;
        pright = pomocna;
        if (pright != pleft)

        {
            postup.push_back(pleft + 1);
            postup.push_back(pright + 1);
            p = p + 2;
        }
        while (pleft < pright)
        {
            swap(hlavny[pleft], hlavny[pright]);
            pright--;
            pleft++;
        }
    }



    if(l == 0){
        cout<<"ANO"<<endl;
    }
    else{
        if(p<l){
            cout << "ANO" << endl;
                p = p / 2;
                cout << p << endl;
                p = p * 2;
                for (int i = 0; i < p; i = i + 2)
                {

                    cout << postup[i] << " " << postup[i + 1] << endl;
                }
        }
        else{
            cout<<"NIE"<<endl;
        }
    }
}
