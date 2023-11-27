#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string myText;
    ifstream MyReadFile("B-tezky.txt");
    vector<int> vysledky;
    MyReadFile >> t;
   
    for(int vsetko=0;vsetko<t;vsetko++){
        int n;
        MyReadFile >> n;
        int rekord=0;
        int vysledok=0;
        for(int i=0;i<n;i++){
            int pomocna;
            MyReadFile >> pomocna;
            if(pomocna>rekord){
                rekord=pomocna;
                vysledok++;

            }
        }
        
        vysledky.push_back(vysledok);

    }
    MyReadFile.close();
    ofstream MyFile("B.txt");
    for(auto i:vysledky){
        MyFile << i << endl;
    }
    MyFile.close();
    
}