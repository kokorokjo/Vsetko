#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> al;
int k;
long long answer = 0;
vector<int> dfs (int index, int parent) {
vector<int> ret(k + 1);
for (int son : al[index]) if (son != parent) {
auto got = dfs(son, index);
answer += got[k - 1];
for (int i = 0; i < k; ++i) {
answer += got[i] * ret[k - i - 1];
}
for (int i = 0; i < k; ++i) {
ret[i + 1] += got[i];
}
}
ret[0]++;
return ret;
}

int main () {
int n;
cin >> n >> k;
al = vector<vector<int>>(n);
for (int i = 0; i < n-1; ++i) {
int x, y;
cin >> x >> y;
x--; y--;
al[x].push_back(y);
al[y].push_back(x);
}
dfs(0, -1);
cout << answer << endl;
}