#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
using namespace std;
void vypis(vector<string> idk)
{
    for (auto i:idk)
    {
        cout<<i<<endl;
    }
}
bool nachadza(string toto,string neviem)
{
    if(toto.size()<neviem.size())
        return false;
    for(int i=0; i<neviem.size(); i++)
    {
        if(toto[i]!=neviem[i])
            return false;
    }
    return true;
}


int bin_search(vector<string> &hlavny,string neviem)
{
    int zaciatok=0;
    int koniec=hlavny.size();
    if(nachadza(hlavny[zaciatok],neviem))
        return zaciatok;

    if(nachadza(hlavny[koniec],neviem))
        return koniec;

    while(zaciatok+1!=koniec)
    {
        int pomocna=(zaciatok+koniec)/2;
        if(nachadza(hlavny[pomocna],neviem))
            return pomocna;

        if (hlavny[pomocna]>neviem)
            koniec=pomocna;
        else
            zaciatok=pomocna;

    }
    if(nachadza(hlavny[zaciatok],neviem)==false&&nachadza(hlavny[koniec],neviem)==false)
    {
        return -1;
    }
    else if(nachadza(hlavny[zaciatok],neviem))
    {
        return zaciatok;
    }
    else
    {
        return koniec;
    }
}

int main()
{
    bool asi=false;
    vector<string> hlavny;
    string vstup;
    vector<char> nasledujuce;
    int uff;

    ifstream MyReadFile("mesta.txt");

    while (getline (MyReadFile, vstup))
    {
        for(int i=0; i<vstup.size(); i++)
        {
            if(vstup[i]==32)
            {
                continue;
            }
            if(vstup[i]<96)
            {

                vstup[i]+=32;
            }
        }
        hlavny.push_back(vstup);
    }
    MyReadFile.close();
    sort(hlavny.begin(),hlavny.end());
    //toto bolo nacitanie suboru a zoradenie

    getline(cin,vstup);
    for(int i=0; i<vstup.size(); i++)
    {
        if(vstup[i]==32)
        {
            continue;
        }
        if(vstup[i]<96)
        {

            vstup[i]+=32;
        }
    }
    //nacita vstup
    int vysledok=bin_search(hlavny,vstup);
    //najde mesto s podstringom zo vstupu
    if(vysledok==-1)
    {
        cout<<"NOT FOUND"<<endl;
        return 0;
    }


    //nad
    for(int i=vysledok; i>=0; i--)
    {
        if(nachadza(hlavny[i],vstup)==false)
            break;
        if(hlavny[i]==vstup)
        {
            cout<<vstup<<endl;
            return 0;
        }
        else
        {
            for(int k=0; k<nasledujuce.size(); k++)
            {
                if(nasledujuce[k]==hlavny[i][vstup.size()])
                {
                    asi=true;
                    break;
                }
            }
            if(asi==false)
            {

                nasledujuce.push_back(hlavny[i][vstup.size()]);

            }
            uff=i;
            asi=false;
        }

    }


    //pod
    for(int i=vysledok+1; i<hlavny.size(); i++)
    {
        if(nachadza(hlavny[i],vstup)==false)
            break;
        if(hlavny[i]==vstup)
        {
            cout<<vstup<<endl;
            return 0;
        }
        else
        {
            for(int k=0; k<nasledujuce.size(); k++)
            {
                if(nasledujuce[k]==hlavny[i][vstup.size()])
                {
                    asi=true;
                    break;
                }
            }
            if(asi==false)
            {

                nasledujuce.push_back(hlavny[i][vstup.size()]);

            }
            uff=i;
            asi=false;
        }
    }
    if(nasledujuce.size()==1)
    {
        cout<<hlavny[uff]<<endl;
        return 0;
    }
    for(auto i:nasledujuce)
    {
        cout<<i<<endl;
    }
    return 0;
}
