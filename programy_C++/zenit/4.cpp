#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;



int main(){
    int n;
    cin >> n;
    for(int asi=0;asi<n;asi++){

    

    string bin_string = "00000000000000000000000000010100";
	unsigned long long number =0;
    cin>>number;

    for(int i=0;i<32;i++){
        if(number%2==1){
            bin_string[i]='1';
        }
        else{
            bin_string[i]='0';
        }
        number/=2;
    }
    
    string s=bin_string;
    // cout<<s<<endl;
    
    unsigned long long sum=0;
    int zasiatok=0;
	for(int i=0;i<32;i++){
        if(s[i]=='1'){
            zasiatok=i;
            break;
        }
        
    }
    for(int i=zasiatok;i<32;i++){
        if(s[i]=='1'){
            sum*=2;
            sum+=1;
            
            
        }
        else{
            sum*=2;
        }
    }
    cout<<sum<<endl;
    }


	return 0;
}

