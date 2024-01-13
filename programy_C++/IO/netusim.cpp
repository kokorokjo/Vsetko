#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, pomocna = 2, prvy, druhy, poradie = 0, pocet = 0;
    cin >> n;
    int aa[n], bb[n], cc[n];
    bool pravda = true;
    for (int i = 0; i < n; i++)
    {
        cin >> aa[i];
    }
    while (pomocna < n)
    {
        while (poradie * pomocna < n)
        {
            prvy = 0 + poradie*pomocna;
            druhy = pomocna + poradie;
            for (int i = 0; i < pomocna; i++)
            {
                if (aa[prvy] < aa[druhy])
                {
                    bb[i] = aa[prvy];
                    prvy++;
                }
                else
                {
                    bb[i] = aa[druhy];
                    druhy++;
                }
                if (prvy == pomocna - 1)
                {
                    for (int k = i; k < pomocna; k++)
                    {
                        bb[k] = aa[druhy];
                        druhy++;
                    }
                    break;
                }
                if (druhy == n)
                {
                    for (int k = i; k < pomocna; k++)
                    {
                        bb[k] = aa[prvy];
                        prvy++;
                    }
                }
            }
            pravda = true;
            poradie++;

            if (pomocna * poradie < n)
            {
                prvy = 0 + poradie*pomocna;
                druhy = pomocna + poradie;
                for (int i = 0; i < pomocna; i++)
                {
                    if (bb[prvy] < bb[druhy])
                    {
                        aa[i] = bb[prvy];
                        prvy++;
                    }
                    else
                    {
                        aa[i] = bb[druhy];
                        druhy++;
                    }
                    if (prvy == pomocna - 1)
                    {
                        for (int k = i; k < pomocna; k++)
                        {
                            aa[k] = bb[druhy];
                            druhy++;
                        }
                        break;
                    }
                    if (druhy == n)
                    {
                        for (int k = i; k < pomocna; k++)
                        {
                            bb[k] = aa[prvy];
                            prvy++;
                        }
                    }
                }
                poradie++;
                pravda = false;
            }
        }
        pomocna = pomocna * 2;
        poradie = 0;
    }
    pomocna = pomocna / 2;
    prvy = 0;
    druhy = pomocna;
    if(pomocna==n){
        for (int i = 0; i < n + 1; i++)
    {
        cout << cc[i] << " ";
    }
    cout << cc[n - 1] << endl;
    return 0;
    }
    if (pravda = true)
    {
        for (int i = 0; i < n; i++)
        {
            if (aa[prvy] < aa[druhy])
            {
                cc[i] = aa[prvy];
                prvy++;
            }
            else
            {
                cc[i] = aa[druhy];
                druhy++;
            }
            if (prvy == pomocna - 1)
            {
                for (int k = i; k < n; k++)
                {
                    cc[k] = aa[druhy];
                    druhy++;
                }
                break;
            }
            if (druhy == n)
            {
                for (int k = i; k < n; k++)
                {
                    cc[k] = aa[prvy];
                    prvy++;
                }
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (bb[prvy] < bb[druhy])
            {
                cc[i] = bb[prvy];
                prvy++;
            }
            else
            {
                cc[i] = bb[druhy];
                druhy++;
            }
            if (prvy == pomocna - 1)
            {
                for (int k = i; k < n; k++)
                {
                    cc[k] = bb[druhy];
                    druhy++;
                }
                break;
            }
            if (druhy == n)
            {
                for (int k = i; k < n; k++)
                {
                    cc[k] = bb[prvy];
                    prvy++;
                }
                break;
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        cout << cc[i] << " ";
    }
    cout << cc[n - 1] << endl;
}