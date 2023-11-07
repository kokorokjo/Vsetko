#include <bits/stdc++.h>
using namespace std;

int main(){
    int m,n,k;
    //n=riadok
    cin >> m >> n >> k;
    bool nie=false;
    vector<vector<char>> hlavny(m, vector<char>(n)),vysledok(m,vector<char>(n,'?'));
    vector<vector<char>> vsetko(n,vector<char>(k*(m)));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k*(m); j++){
            cin >> vsetko[i][j];
        }
    }
    
   
    for(int i=0;i<k;i++){

        for(int j=0;j<m;j++){
            for(int l=0;l<n;l++){
                hlavny[j][l]=vsetko[j][l+i*n];
            }
        }
        int posunDoPrava=0;
        for(int j=0;j<m;j++){
            for(int l=0;l<n;l++){
                if(hlavny[j][l]=='.')
                else{
                    nie=true;
                    break;
                } 
            }
            if(nie==true){
                break;
                nie=false;
            }
            else{
                posunDoPrava++;
            }
        }
        if(posunDoPrava!=0){
            for(int j=posunDoPrava;j<m;j++){
                for(int l=0;l<n;l++){
                    if(hlavny[j][l]=='?'){
                        continue;
                    }
                    if(vysledok[j-posunDoPrava][l]=='?'){
                        vysledok[j-posunDoPrava][l]=hlavny[j][l];
                    }
                    else if(vysledok[j-posunDoPrava][l]==hlavny[j][l]){
                        continue;
                    }
                    else{
                        cout<<pokazeny<<endl;
            return 0;
                    }

                }
            }

        }
        int posunDoLava=0;
        else {
            
            for(int j=m-1;j>=0;j--){
                for(int l=0;l<n;l++){
                    if(hlavny[j][l]=='.')
                    else{
                        nie=true;
                        break;
                    } 
                }
                if(nie==true){
                    break;
                    nie=false;
                }
                else{
                    posunDoLava++;
                }
            }
            for(int j=0;j<m-posunDoLava;j++){
                for(int l=0;l<n;l++){
                    if(hlavny[j][l]=='?'){
                        continue;
                    }
                    if(vysledok[j+posunDoLava][l]=='?'){
                        vysledok[j+posunDoLava][l]=hlavny[j][l];
                    }
                    else if(vysledok[j+posunDoLava][l]==hlavny[j][l]){
                        continue;
                    }
                    else{
                        cout<<"pokazeny"<<endl;
            return 0;
                    }

                }

            }

        }
        if(posunDoPrava==0&&posunDoLava==0){
            for(int j=0;j<m;j++){
                for(int l=0;l<n;l++){
                    if(hlavny[j][l]=='?'){
                        continue;
                    }
                    if(vysledok[j][l]=='?'){
                        vysledok[j][l]=hlavny[j][l];
                    }
                    else if(vysledok[j][l]==hlavny[j][l]){
                        continue;
                    }
                    else{
                        cout<<pokazeny<<endl;
            return 0;
                    }

                }

            }

        }
        

       
   
    


    }
    
}