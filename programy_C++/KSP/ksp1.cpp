#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
 string hlavny;
 getline (cin,hlavny);
 int zrazky=0;
 int idk=0;
 int pocet=0;
while(hlavny[idk]=='<'){
        idk++;
}
for(int i=idk;i<hlavny.length();i++){
     if(hlavny[i]=='>'){
        pocet++;
     }
     if(hlavny[i]=='<'){

            zrazky+=pocet;
            pocet=0;
            zrazky++;}
        if(hlavny[i]=='='){
            zrazky+=pocet;
            pocet=0;
        }
     
 }
 cout<<zrazky<<endl;
}
//||