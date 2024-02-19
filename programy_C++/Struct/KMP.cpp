#include <bits/stdc++.h>
using namespace std;



vector<int> KMP(string text, string pattern)
{
    vector<int> next(pattern.size()+1);

    
    next[0] = -1;
    for(int i=0; i<pattern.size(); i++)
    {
        int back = next[i];
        while(back >= 0 && pattern[i] != pattern[back]) back = next[back];
        next[i+1] = back+1;
    }

    
    vector<int> result;
    int position = 0;
    for(int i=0; i<text.size(); i++)
    {
        while(position >= 0 && text[i] != pattern[position]) position = next[position];
        position++;
        if(position == pattern.size())
        {
            result.push_back(i+1-pattern.size());
            position = next[position];
        }
    }
    return result;
}

int main(){

    int l,w;
    cin >> l >> w; 
    for(int i=0;i<w;i++){
    string text;
    string vzor;
    cin  >> vzor >> text;
    vector<int> vysledok = KMP(text,vzor);
    if (vysledok.size()==0){
        cout<<"NOT OK"<<endl;
    }
    else{
        cout<<"OK"<<endl;
    }
}    
    return 0;
}