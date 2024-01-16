#include <bits/stdc++.h>

using namespace std;

bool podmienka(vector<vector<int>>& sachovnica, int riadok, int stlpec, int n) {
    for (int i = 0; i < stlpec; ++i) {
        if (sachovnica[riadok][i] == 1) {
            return false;
        }
    }
    for (int i = riadok, j = stlpec; i >= 0 && j >= 0; --i, --j) {
        if (sachovnica[i][j] == 1) {
            return false;
        }
    }
    for (int i = riadok, j = stlpec; i < n && j >= 0; ++i, --j) {
        if (sachovnica[i][j] == 1) {
            return false;
        }
    }
    return true;
}

bool rekurzia(vector<vector<int>>& sachovnica, int stlpec, int n) {
    if (stlpec >= n) {
        return true; 
    }
    for (int i = 0; i < n; i++) {
        if (podmienka(sachovnica, i, stlpec, n)) {
            sachovnica[i][stlpec] = 1;

            if (rekurzia(sachovnica, stlpec + 1, n)) {
                return true;
            }

            sachovnica[i][stlpec] = 0;
        }
    }

    return false;
}
    

int main() {
    int n=8;
    vector<vector<int>> sachovnica(n, vector<int>(n, 0));

    rekurzia(sachovnica, 0, n);
    

    for (auto riadok : sachovnica) {
        for (auto val : riadok) {
            cout << val << " ";
        }
        cout << endl;
    }
}
