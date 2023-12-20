#include <bits/stdc++.h>
using namespace std;


int SIZE = 6;
int najviac=0;
vector<vector<bool>> vysledny;
vector<pair<int, int>> positions,vysledok;
vector<vector<bool>> visited(SIZE, vector<bool>(SIZE, false));


bool isValid(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && !visited[x][y];
}

void findLongestPath(int x, int y, int steps) {
    int dx[] = {2, 1, -1, -2, 2, 1, -1, -2};
    int dy[] = {1, 2, -2, -1, -1, -2, 2, 1};

    int maxLength = steps;

    for (int i = 0; i < 8; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY)) {
            visited[newX][newY] = true;
            positions.push_back({newX, newY});
            findLongestPath(newX, newY, steps + 1);
            visited[newX][newY] = false;
            positions.pop_back();
        }
    }
    if(maxLength>najviac) {
        najviac=maxLength;
        vysledok=positions;
        vysledny=visited;
    }
}

int main() {
    visited[0][0] = true;
    findLongestPath(0, 0, 1);

    cout << "Najdlhšia možná cesta strelca: " << najviac << " krokov." << endl;
    cout << "Cesta: " << endl;
    for (auto position : vysledok) {
        cout << position.first << " " << position.second << endl;
    }
    cout << "visited: " << endl;
    for (auto row : vysledny) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
