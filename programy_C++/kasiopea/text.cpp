#include <bits/stdc++.h>
using namespace std;

int main(){
    // ofstream MyFile("f1.txt");
    // MyFile << "Files can be tricky, but it is fun enough!";
    // MyFile.close();

    // string myText;
    // ifstream MyReadFile("f1.txt");
    // while (getline (MyReadFile, myText)) {
    // cout << myText;
    // }
    // MyReadFile.close();
    ifstream MyReadFile("text.txt");
    int a;
    MyReadFile >> a;
    cout << a;
    int b;
    MyReadFile >> b;
    cout << b;
    MyReadFile.close();
}