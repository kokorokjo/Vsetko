#include <string>
#include <vector>
#include <iostream>
using namespace std;

string alphabet_position(const string &text) {
    string text2;
    int a;
  for(int i=0;i<text.length();i++){
    if(text[i]<='z' && text[i]>='a'){
      if(text2.length()>0){
        text2+=" ";
      }
      a=text[i]-73-23;
      //cout<<text[i]<<" "<<a<<endl;
      text2+=to_string(a);
      //97=a=24+73
    }
    else if(text[i]<='Z' && text[i]>='A'){
      if(text2.length()>0){
        text2+=" ";
      }
      a=text[i]-41-23;
      //cout<<text[i]<<" "<<a<<endl;
      text2+=to_string(a);
      //65=A=24+41
    }
    
  }
  return text2;
}


int main(){
  string text="The sunset sets at twelve o' clock.";
  string text2=alphabet_position(text);
  cout<<text2;
  return 0;
}