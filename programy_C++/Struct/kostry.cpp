#include <bits/stdc++.h>   
using namespace std;

struct hrany
{   
    int x;
    int y;
    int vaha;  
};
bool porovnanie(const hrany &a, const hrany &b ) {
    return a.vaha < b.vaha;
}
int najdenieKorena(vector<int>& rodic, int i) {
    if (rodic[i] == -1)
        return i;
    auto res = najdenieKorena(rodic, rodic[i]);
    rodic[i] = res;
    return res;
    
}
void zlucenieStromov(vector<int>& rodic, int x, int y) {
    int rootX = najdenieKorena(rodic, x);
    int rootY = najdenieKorena(rodic, y);
    rodic[rootX] = rootY;
}


int main() {
    int n, m;
    cin >> n >> m;

    vector<hrany> hrana(m);

    for (int i = 0; i < m; ++i) {
        cin >> hrana[i].x >> hrana[i].y >> hrana[i].vaha;
    }

    sort(hrana.begin(), hrana.end(),porovnanie);
    vector<int> rodic(n + 1, -1); 
    int minCena = 0; 
    int maxCena = 0; 

    for(int i=0;i<hrana.size();i++){
        int rootA = najdenieKorena(rodic, hrana[i].x);
        int rootB = najdenieKorena(rodic, hrana[i].y);
        if (rootA != rootB) {
            minCena += hrana[i].vaha;
            zlucenieStromov(rodic, rootA, rootB);
        }
    }
    reverse(hrana.begin(), hrana.end());
    fill(rodic.begin(), rodic.end(), -1);

    for(int i=0;i<hrana.size();i++){
        int rootA = najdenieKorena(rodic, hrana[i].x);
        int rootB = najdenieKorena(rodic, hrana[i].y);
        if (rootA != rootB) {
            maxCena += hrana[i].vaha;
            zlucenieStromov(rodic, rootA, rootB);
        }
    }
    cout << minCena << " " << maxCena << endl;



    



    return 0;
}