#include <bits/stdc++.h>
using namespace std;
int main() {
int N; cin >> N;
vector<int> A(N); for (int &a : A) cin >> a;
// predpocitame B a jeho prefixove sucty
vector<int> B(N); for (int n=0; n<N; ++n) B[n] = int( A[n] == n );
vector<int> SB(1, 0); for (int b : B) SB.push_back( SB.back()+b );
// usporiadame vsetky zle prvky podla stredu a v ramci stredu podla dlzky reverzu
vector< vector<int> > podla_dlzky(N);
for (int n=0; n<N; ++n) if (A[n] != n) podla_dlzky[ abs(A[n]-n) ].push_back(n);
vector< vector<int> > podla_stredu(2*N-1);
for (auto row : podla_dlzky) for (int x : row) podla_stredu[ x+A[x] ].push_back(x);
// prejdeme vsetkych kandidatov na najlepsie riesenie
int bestupr = SB[N], bestzac = 0, bestkon = 0;
for (int stred=0; stred<2*N-1; ++stred) {
for (int i=0; i<int(podla_stredu[stred].size()); ++i) {
int x = podla_stredu[stred][i];
int dlzka = abs( A[x] - x );
int zac = (stred-dlzka)/2, kon = (stred+dlzka)/2;
// prezerame usek od zac po kon
int upr = SB[N]; // tolkoto bola upratanost pred reverzom
upr += (i+1); // tolkoto nadejnych prvkov sme reverzom zmenili na dobre
upr -= SB[kon+1] - SB[zac]; // tolkoto dobrych prvkov sme reverzli
if (stred%2 == 0 && A[stred/2] == stred/2) ++upr; // dobry prvok v strede reverzu zostal dobry
if (upr > bestupr) {
// nasli sme nove optimum
bestupr = upr; bestzac = zac; bestkon = kon;
}
}
}
cout << bestzac << " " << bestkon << endl;
}
