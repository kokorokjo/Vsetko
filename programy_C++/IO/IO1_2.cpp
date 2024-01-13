#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, l, ke, pomocna, right = 0, left = 0, pright, pleft, hodnota, p = 0, idk, koniecR, koniecL;
    cin >> n >> k >> l;
    vector<int> hlavny(n),zoradeny(n),postup(0);
    bool LPravda=false, pravda=false;
    k--;
    for (int i = 0; i < n; i++)
    {
        cin >> hlavny[i];
    }
    zoradeny=hlavny;
    sort(zoradeny.begin(), zoradeny.end());
    ke=hlavny[k];
    if(zoradeny[k]!=hlavny[k])
    {
        cout<<"NIE"<<endl;
        return 0;
    }

    else
    {
        if(l==0)
        {
            cout<<"ANO"<<endl;
            return 0;
        }
        else
        {
            cout<<"ANO"<<endl;
            for (int i = 0; i < k; i++)
            {
                hodnota = hlavny[i];
                pomocna = i;
                for (int f = i; f < k; f++)
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
            for (int i = k+1; i < n; i++)
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

            right=0;
            left=0;
            idk=0;
            if(k!=0)
            {

                if(hlavny[k-1]>ke)
                {

                    pomocna=hlavny[k-1];

                }
                else
                {
                    pomocna=ke-1;
                }
                while(pomocna>ke)
                {
                    left++;
                    if(k-left==0)
                    {
                        break;
                    }
                    pomocna=hlavny[k-left-1];
                }
            }
            if(k!=n-1)
            {
                if(hlavny[k+1]<ke)
                {

                    pomocna=hlavny[k+1];
                }
                else
                {
                    pomocna=ke+1;
                }
                while(pomocna<ke)
                {
                    right++;
                    if(k+right==n-1)
                    {
                        break;
                    }
                    pomocna=hlavny[right+k+1];
                }
            }

            if(right<left)
            {
                idk=left;
            }
            else
            {
                idk=right;
            }
            if(idk==0)
            {
                cout<<p/2<<endl;
                for(int i = 0; i<=p-1; i++)
                {
                    cout<<postup[i]<<" "<<postup[i+1]<<endl;
                    i++;
                }
                /*for(auto i:hlavny)
                {
                    cout<<i<<" ";
                }
                cout<<endl;*/
                return 0;
            }

            pleft = k-idk;
            pright = k+idk;


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
           /* for(auto i:hlavny)
            {
                cout<<i<<" ";
            }
            cout<<endl;
*/

            //funguje
            int pozicia;
            koniecL=k+1;
            koniecR=n-1;
            if(k+idk==koniecR)
            {
                pozicia=k+idk;
                LPravda=false;
                pravda=true;
            }
            else if(hlavny[k+idk]==zoradeny[k+1])
            {
                pozicia=k+idk;
                LPravda=true;
            }
            else
            {
                pozicia=k+idk+1;
                LPravda=false;
            }
            for(int i=0; i<n-k-1; i++)
            {
                pravda=true;
                if(LPravda)
                {

                    if(pozicia==koniecL||pozicia==koniecR)
                    {
                        break;
                    }
                    else if(pozicia+i==koniecR)
                    {


                        pright = koniecR;
                        pleft = pozicia;

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
                        break;
                    }
                    else
                    {
                        if(hlavny[pozicia-1]==zoradeny[k+i+2])
                        {
                            LPravda=false;
                            pleft = pozicia;
                            pright = pozicia+i;
                            if (pright != pleft)

                            {
                                postup.push_back(pleft + 1);
                                postup.push_back(pright + 1);
                                p = p + 2;
                            }
                            pozicia=pozicia+i;
                            while (pleft < pright)
                            {
                                swap(hlavny[pleft], hlavny[pright]);
                                pright--;
                                pleft++;
                            }

                        }

                    }
                }
                else
                {

                    if(pozicia==koniecR||pozicia==koniecL)
                    {
                        break;
                    }
                    else if(pozicia-i==koniecL)
                    {


                        pleft = koniecL;
                        pright = pozicia;

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
                        break;
                    }
                    else
                    {
                        if(hlavny[pozicia+1]==zoradeny[k+i+2])
                        {
                            LPravda=true;
                            pleft = pozicia-i;
                            pright = pozicia;

                            if (pright != pleft)

                            {
                                postup.push_back(pleft + 1);
                                postup.push_back(pright + 1);
                                p = p + 2;
                            }
                            pozicia=pozicia-i;
                            while (pleft < pright)
                            {
                                swap(hlavny[pleft], hlavny[pright]);
                                pright--;
                                pleft++;
                            }
                        }

                    }

                }
            }
            if(pravda)
            {
                if(hlavny[koniecR]==zoradeny[k+1])
                {
                    pleft = k+1;
                    pright = n-1;
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
            }

            //snad funguje pravo triedenie
            pravda=false;

            koniecL=0;
            koniecR=k-1;
            if(k-idk==koniecL)
            {
                pozicia=k-idk;
                LPravda=false;
                pravda=true;
            }
            else if(hlavny[k-idk]==zoradeny[k-1])
            {
                pozicia=k-idk;
                LPravda=true;
            }
            else
            {
                pozicia=k-idk-1;
                LPravda=false;
            }
            for(int i=0; i<k-1; i++)
            {
                pravda=true;
                if(LPravda)
                {


                    if(pozicia==koniecL||pozicia==koniecR)
                    {

                        break;
                    }
                    else if(pozicia+i==koniecR)
                    {


                        pright = koniecR;
                        pleft = pozicia;

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
                        break;
                    }
                    else
                    {

                        if(hlavny[pozicia-1]==zoradeny[k-i-2])
                        {
                            LPravda=false;

                            pleft = pozicia;
                            pright = pozicia+i;
                            if (pright != pleft)

                            {
                                postup.push_back(pleft + 1);
                                postup.push_back(pright + 1);
                                p = p + 2;

                                pozicia=pozicia+i;

                            }

                            while (pleft < pright)
                            {
                                swap(hlavny[pleft], hlavny[pright]);
                                pright--;
                                pleft++;
                            }


                        }

                    }
                }
                else
                {


                    if(pozicia==koniecR||pozicia==koniecL)
                    {
                        // cout<<"somtu5"<<endl;
                        break;
                    }
                    else if(pozicia-i==koniecL)
                    {
//cout<<"somtu6"<<endl;

                        pleft = koniecL;
                        pright = pozicia;

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
                        break;
                    }
                    else
                    {
                        //cout<<"somtu7"<<endl;
                        if(hlavny[pozicia+1]==zoradeny[k-i-2])
                        {

                            pleft = pozicia-i;
                            pright = pozicia;
                            LPravda=true;
                            if (pright != pleft)

                            {
                                postup.push_back(pleft + 1);
                                postup.push_back(pright + 1);
                                p = p + 2;
                                pozicia=pozicia-i;
                            }

                            while (pleft < pright)
                            {
                                swap(hlavny[pleft], hlavny[pright]);
                                pright--;
                                pleft++;
                            }

                        }

                    }

                }
            }
            if(pravda)
            {
                if(hlavny[koniecL]==zoradeny[k-1])
                {
                    pleft = koniecL;
                    pright = k-1;
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
            }












        }
    }




    cout<<p/2<<endl;
    for(int i = 0; i<=p-1; i++)
    {
        cout<<postup[i]<<" "<<postup[i+1]<<endl;
        i++;
    }
    /*for(auto i:hlavny)
    {
        cout << i<<" ";

    }
    cout<<endl;
    */




}
