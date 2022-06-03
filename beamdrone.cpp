#include <bits/stdc++.h>
using namespace std;
// matrice de int-uri care reprezinta
// elementele citite de la tastatura
// daca e perete, valoarea din matrice va fi -1
// daca e spatiu liber valoarea din matrice va fi 0
int adj[1000][1000];
#define NMAX 50005

// valoare mai mare decat orice distanta
#define INF (1 << 30)

int bfs(int xi, int yi, int xf, int yf, int n, int m) {
    vector<vector<int>> distances(n, vector<int>(m, INF));
    int i, j;
    queue<pair<int, int>> q;
    q.push({xi, yi});
    distances[xi][yi] = -1;
    while (!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        int coord_x = node.first;
        int coord_y = node.second;
        for (i = coord_x - 1; i >= 0; i--) {
            // for N
            if (adj[i][coord_y] == -1 || distances[i][coord_y] != INF &&
            (distances[coord_x][coord_y] + 1 > distances[i][coord_y])) {
                break;
            }
            // reactulizam distanta doar atunci cand obtinem
            // o valoare numerica mai mica decat ce aveam deja
            distances[i][coord_y] = 1 + distances[coord_x][coord_y];
            q.push({i, coord_y});
        }
        for (i = coord_x + 1; i < n; i++) {
            // for S
            if (adj[i][coord_y] == -1 || distances[i][coord_y] != INF &&
            (distances[coord_x][coord_y] + 1 > distances[i][coord_y])) {
                break;
            }
            // reactulizam distanta doar atunci cand obtinem
            // o valoare numerica mai mica decat ce aveam deja
            distances[i][coord_y] = 1 + distances[coord_x][coord_y];
            q.push({i, coord_y});
        }
        for (i = coord_y + 1; i < m; i++) {
            // for E
            if (adj[coord_x][i] == -1 || distances[coord_x][i] != INF &&
            (distances[coord_x][coord_y] + 1 > distances[coord_x][i])) {
                break;
            }
            // reactulizam distanta doar atunci cand obtinem
            // o valoare numerica mai mica decat ce aveam deja
            distances[coord_x][i] = 1 + distances[coord_x][coord_y];
            q.push({coord_x, i});
        }
        for (i = coord_y - 1; i >= 0; i--) {
            // for W
            if (adj[coord_x][i] == -1 || distances[coord_x][i] != INF &&
            (distances[coord_x][coord_y] + 1 > distances[coord_x][i])) {
                break;
            }
            // reactulizam distanta doar atunci cand obtinem
            // o valoare numerica mai mica decat ce aveam deja
            distances[coord_x][i] = 1 + distances[coord_x][coord_y];
            q.push({coord_x, i});
        }
    }
    return distances[xf][yf];
}

int main() {
    int n, m, xi, yi, xf, yf, i, j;
    ifstream fin("beamdrone.in");
    ofstream fout("beamdrone.out");
    fin >> n >> m;
    fin >> xi >> yi >> xf >> yf;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            char c;
            fin >> c;
            if (c == 'W') {
                adj[i][j] = -1;
            } else {
                adj[i][j] = 0;
            }
        }
    }
    // extragem costul minim obtinut in urma bfs-ului
    int dist = bfs(xi, yi, xf, yf, n, m);
    fout << dist << endl;
    return 0;
}
