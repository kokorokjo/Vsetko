#include <bits/stdc++.h>
#define INF 99999999999.0

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int n;
double beta, lambda;
vector<pll> steny;
double jedna_stena (pll x) {
return max(beta / x.first, lambda / x.second);
}
// Predpokladame, ze x aj y lezia na hornej casti konvexniho obalu, a teda nemusime
// riesit specialne pripady, len pripad kedy nastanu dve rovnosti.
double dve_steny (pll x, pll y) {
double t2 = (lambda*x.first - beta*x.second) / (x.first*y.second - x.second*y.first);
double t1 = (beta - t2*b2) / b1;
if (t2 >= 0 && t1 >= 0) return t1 + t2; else return INF;
}

int main() {
cin >> n >> beta >> lambda;
ll b, l;
ll maxb = -1, maxl = -1
for (int i = 0; i < n; ++i) {
cin >> b >> l;
steny.push_back({ b, l });
maxb = max(maxb, b);
maxl = max(maxl, l);
}
steny.push_back({ maxb, 0 });
steny.push_back({ 0, maxl });
// Funkcia upper_convex_hull najde hornu polovicu konvexneho obalu.
// Na jej zaciatku a konci budu body { maxb, 0 } a { 0, maxl }.
vector<pll> obal = upper_convex_hull(steny);
int m = obal.size();
// Vyskusame moznosti trenovat len na prvej / len na poslednej stene konvexneho obalu.
double result = min(jedna_stena(obal[1]), jedna_stena(obal[m - 2]));
// Vyskusame moznosti trenovat na dvoch "susednych" stenach.
for (int i = 1; i < m-2; ++i) result = min(result, dve_steny(obal[i], obal[i+1]));
return result;
}
