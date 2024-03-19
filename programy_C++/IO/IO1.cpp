#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    vector<int> A(N), P(N+1,0);
    for (int n=0; n<N; ++n) { int a; cin >> a; A[n] = (a>=D ? 1 : -1); P[n+1] = P[n] + A[n]; }

    vector<int> videl(2*N+1,0); // videl[N+i] hovorí, koľko už spracovaných prvkov P malo hodnotu presne i
    int leq = 0; // počet už spracovaných prvkov P ktoré boli menšie alebo rovné ako aktuálny
    int odpoved = 0;
    for (int n=1; n<=N; ++n) {
// pridáme prvok P[n-1] medzi už videné, aj medzi prvky <= ako aktuálny
        ++videl[ N+P[n-1] ];
        ++leq;
// posunieme aktuálny prvok na P[n], čím buď pribudnú alebo ubudnú skôr spracované <= od neho
        if (P[n] == P[n-1] + 1) leq += videl[ N+P[n] ]; else leq -= videl[ N+P[n-1] ];
    odpoved += leq;
}
cout << odpoved << endl;
}