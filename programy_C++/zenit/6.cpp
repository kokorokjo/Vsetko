#include <bits/stdc++.h>
using namespace std;

int main(){
    string zenit = "ZENIT";
    int n;
    cin >> n;
    vector<vector<char>> a(n+2, vector<char>(n+2,'Q'));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(a[i][j] == 'Z'){
                if(a[i+1][j] == 'E' ){
                    if(a[i+2][j] == 'N'){
                        if(a[i+3][j] == 'I'){
                            if(a[i+4][j] == 'T'){
                                cout << "OK" << endl;
                                return 0;
                            }
                        }
                    }
                    
                }
                if(a[i-1][j]=='E'){
                    if(a[i-2][j]=='N'){
                        if(a[i-3][j]=='I'){
                            if(a[i-4][j]=='T'){
                                cout << "OK" << endl;
                                return 0;
                            }
                        }
                    }

                }
                if(a[i][j+1]=='E'){
                    if(a[i][j+2]=='N'){
                        if(a[i][j+3]=='I'){
                            if(a[i][j+4]=='T'){
                                cout << "OK" << endl;
                                return 0;
                            }
                        }
                    }

                }
                 if(a[i][j-1]=='E'){
                    if(a[i][j-2]=='N'){
                        if(a[i][j-3]=='I'){
                            if(a[i][j-4]=='T'){
                                cout << "OK" << endl;
                                return 0;
                            }
                        }
                    }


                }
                 if(a[i+1][j+1]=='E'){
                    if(a[i+2][j+2]=='N'){
                        if(a[i+3][j+3]=='I'){
                            if(a[i+4][j+4]=='T'){
                                cout << "OK" << endl;
                                return 0;
                            }
                        }
                    }

                }
                 if(a[i-1][j-1]=='E'){
                    if(a[i-2][j-2]=='N'){
                        if(a[i-3][j-3]=='I'){
                            if(a[i-4][j-4]=='T'){
                                cout << "OK" << endl;
                                return 0;
                            }
                        }
                    }

                }
                 if(a[i+1][j-1]=='E'){
                    if(a[i+2][j-2]=='N'){
                        if(a[i+3][j-3]=='I'){
                            if(a[i+4][j-4]=='T'){
                                cout << "OK" << endl;
                                return 0;
                            }
                        }
                    }

                }
                 if(a[i-1][j+1]=='E'){
                    if(a[i-2][j+2]=='N'){
                        if(a[i-3][j+3]=='I'){
                            if(a[i-4][j+4]=='T'){
                                cout << "OK" << endl;
                                return 0;
                            }
                        }
                    }

                }

                
            }
            
        }
    }
    cout<<"WA"<<endl;
    // for(int i=0;i<a.size();i++){
    //     for(int j=0;j<a[i].size();j++){
    //         cout<<a[i][j];
    //     }
    //     cout<<endl;
        
    // }
}