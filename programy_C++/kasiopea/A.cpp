#include <bits/stdc++.h>
using namespace std;

int main(){
    string myText;
    ifstream MyReadFile("A-lehky (3).txt");
    getline (MyReadFile, myText);
    int t;
    t=stoi(myText);
    vector<int> vysledky;
    
    for(int vsetjko=0;vsetjko<t;vsetjko++){
        int S,D,P,Z;
        getline (MyReadFile, myText);
        S=stoi(myText);
        
        getline (MyReadFile, myText);
        D=stoi(myText);
        
        getline (MyReadFile, myText);
        P=stoi(myText);
        getline (MyReadFile, myText);
        Z=stoi(myText);
        
        int dokopy=P+Z;
        int pocet=0;
        if(dokopy<S+S-dokopy){
            vysledky.push_back(dokopy+D);
        }
        else{
           vysledky.push_back(S+S-dokopy+D);
        }

    }
    for(auto i:vysledky){
        cout << i << endl;
    }
    ofstream MyFile("f1.txt");
    for(auto i:vysledky){
        MyFile << i << endl;
    }
    MyFile.close();
    MyReadFile.close();

}