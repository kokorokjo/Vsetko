#include <bits/stdc++.h>
using namespace std;



int main(){

    int n;
    cin >> n;
   
    for(int vsetko=0;vsetko<n;vsetko++){
        int vysledok=INT_MAX;
        string hlavny;
        cin>>hlavny;
        string pomocny=hlavny;
        vector<pair<int,char>> cisielka;
        vector<int> cisielka2(123,-1);
        cisielka.push_back(make_pair(1,hlavny[0]));
        cisielka2[hlavny[0]]=1;
        pomocny[0]='1';
        for(int i=0;i<hlavny.size();i++){
            if(cisielka2[hlavny[i]]==-1){
                cisielka.push_back(make_pair(0,hlavny[i]));
                cisielka2[hlavny[i]]=0;
                pomocny[i]='0';
                break;
            }
        }
        //  cout<<"este"<<pomocny<<endl;
        for(int i=0;i<hlavny.size();i++){
            int pomocne=-1;
            
                if(cisielka2[hlavny[i]]!=-1){
                    pomocne=cisielka2[hlavny[i]];
                }
            if(pomocne==-1){
                cisielka.push_back(make_pair(cisielka.size(),hlavny[i]));
                cisielka2[hlavny[i]]=cisielka.size();
                pomocny[i]=cisielka.size()+48-1;
            }
            else{
                pomocny[i]=pomocne+48;
            }

        }
        //  cout<<pomocny<<endl;

        
        for(int sustava=cisielka.size();sustava<=10;sustava++){
            if(sustava==1){
                continue;
            }
            int pocet=0;
            for(int i=0;i<pomocny.size();i++){
                pocet*=sustava;
                pocet+=pomocny[i]-48;
            }
            // cout<<sustava<<" "<<pocet<<endl;
            if(pocet<vysledok){
                vysledok=pocet;
            }
        }
        cout<<vysledok<<endl;







    }



}