
#include <bits/stdc++.h>

using namespace std;

void printCombinations(string neviem, int size, int k) {
    if (size == 0) {
        cout << neviem << endl;
        return;
    }
    for (int i=0;i<k; i++) {
        string newPrefix = prefix + (char)('a' + i);
        printCombinations(neviem, size - 1, k);
    }
}

int main() {
    int n,k;
    cin>>n>>k;
    printCombinations("", n, k);
    return 0;
}
