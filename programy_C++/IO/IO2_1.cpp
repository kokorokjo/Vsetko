#include <bits/stdc++.h>
using namespace std;

void vypis (vector<int> pole)
{
    for (auto i : pole)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    int n, p, pomocna, odstranene=0, velkost, m, L, R;
    cin >> n;
    vector<int> hlavny(0), vrcholy(0), doliny(0), vstup(n+1);
    bool uz = false;
    vstup[0]=0;

    for(int i=1; i<=n; i++)
    {
        cin>>vstup[i];
    }
    vstup.push_back(0);
    //nahodene cisla do vectora+ na zaciatku a konci je 0
    int max = *max_element(vstup.begin(), vstup.end());


    p=0;
    for (int i = 1; i < n+1; i++)
    {
        if(vstup[i]>vstup[i-1-odstranene] && vstup[i]>vstup[i+1])
        {
            if(p==0)
            {

            }
            else
            {
                hlavny.push_back(p);
                doliny.push_back(p);
            }
            p=vstup[i+1];
            hlavny.push_back(vstup[i]);
            vrcholy.push_back(vstup[i]);
            odstranene=0;


        }
        else if(vstup[i]<vstup[i-1])
        {
            if(p>vstup[i])
            {
                p=vstup[i];
            }
            odstranene=0;
        }
        else if(vstup[i]==vstup[i-1])
        {
            odstranene++;
        }
        else if(vstup[i]>vstup[i-1]&&vstup[i]==vstup[i+1])
        {

            odstranene=1;
        }


    }
    //uprevene vrch dolina vrch dolina...dolina vrch
 //idem urobit strom pre vrchly   
    
n=1;
int kolko=0;
while (vrcholy.size()>n)
{
    n *= 2;
    kolko++;
}
vector<int> strom(2*n,0);
pomocna=n;
int zaciatok=n;
for (int i=pomocna;i<vrcholy.size()+pomocna;i++){
    strom[i]=vrcholy[i-pomocna];
}
pomocna/=2;

int s;
for (int k=0;k<kolko;k++){
    s=0;
    for (int i=pomocna;i<pomocna*2;i++){
        if(strom[pomocna+i+s]>strom[pomocna+i+1+s]){
            strom[i]=strom[pomocna+i+s];
        }
        else{
            strom[i]=strom[pomocna+i+1+s];
        }
        s++;
    }
    pomocna/=2;

}
// tu som urobil pre vrcholy a idem pre doliny
n=1;
kolko=0;
while (doliny.size()>n)
{
    n *= 2;
    kolko++;
}
vector<int> stromD(2*n,max);
pomocna=n;
for (int i=pomocna;i<doliny.size()+pomocna;i++){
    stromD[i]=doliny[i-pomocna];
}
pomocna/=2;


for (int k=0;k<kolko;k++){
    s=0;
    for (int i=pomocna;i<pomocna*2;i++){
        if(stromD[pomocna+i+s]<stromD[pomocna+i+1+s]){
            stromD[i]=stromD[pomocna+i+s];
        }
        else{
            stromD[i]=stromD[pomocna+i+1+s];
        }
        s++;
    }
    pomocna/=2;

}
//urobil strom pre doliny
// idem urobit najdenie najblizsich vacsich vrcholov

for (int i=zaciatok;i<vrcholy.size()+zaciatok;i++){
   
    if(strom[i]==max){
        cout<<max<<endl;
    }
    else if(i==zaciatok){
        for (int k=i;i>1;k/=2){
            if(strom[k]>strom[i]){
                pomocna=k;
                break;
            }
        }
        m=pomocna;
        while(m<zaciatok){
           if(strom[m*2]>strom[i]){
               m*=2;
           } 
           else{
               m=m*2+1;
           }
        }
        cout<<m<<strom[m]<<endl;
        
    }
    else if(i==vrcholy.size()+zaciatok-1){
      
        for (int k=i;i>1;k/=2){
            if(strom[k]>strom[i]){
                pomocna=k;
                break;
            }
        }
        m=pomocna;
        while(m<zaciatok){
           if(strom[m*2+1]>strom[i]){
              m=m*2+1;
           } 
           else{
               m*=2;
           }
        }
        cout<<m<<strom[m]<<endl;
    }
    else{
        //dokoncit
    }
}

    
    /*vypis(stromD);
    vypis(strom);
    vypis(doliny);
    vypis(vrcholy);
    vypis(hlavny);
    vypis(vstup);*/

    return 0;
}
