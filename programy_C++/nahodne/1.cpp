#include <iostream>
using namespace std;

bool is_prime(long long n) {
    if (n == 1) {
        return false;
    }

    int i = 2;

    while (i*i <= n) {
        
        if (n % i == 0) {
            return false;
        }
        i += 1;
    }
   
    return true;
}

int main() {
    int t;
    cin >> t;
    for(int x=0; x<t; x++) {
        long long n;
        cin >> n;
        cout  << (is_prime(n) ? "ANO" : "NIE") << endl;
        
    }

    return 0;
}