#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;
    int vysledok=0;
    
    for(int asi=0;asi<n;asi++){
        string neviem;
        cin>>neviem;
        for(int sustava=2;sustava<11;sustava++){
            string kopia=neviem;
            vector<pair<char,int>> v;
            int pocitadlo=0;
            v.push_back(make_pair(kopia[0],1));
            kopia[0]=49;
            for(int i=1;i<kopia.size();i++){
                bool je=false;
                for(int j=0;j<v.size();j++){
                    if(v[j].first==kopia[i]){
                        kopia[i]=v[j].second+49;
                        je=true;
                        break;

                    }
                }
                if(!je){
                    if(v.size()==1){
                        kopia[i]=48;
                        v.push_back(make_pair(kopia[i],0));
                    
                    }
                    else{
                    v.push_back(make_pair(kopia[i],v.size()-1));
                    kopia[i]=v.size()+47;
                    }
                }
            }

            cout<<"sustava"<<sustava<<"asi"<<kopia<<endl;
            int sum=0;

            for(int i=0;i<kopia.size();i++){ 
                sum*=sustava;
                sum+=kopia[i]-48;
                }
                cout<<sum<<endl;
        if(sum>vysledok){
            vysledok=sum;
        }






        }
        
    }
    //48


}