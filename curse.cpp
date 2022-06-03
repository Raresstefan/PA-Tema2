#include <bits/stdc++.h>
using namespace std;
// matricea de adiacenta
vector<int> adj[1000001];
int m;

void dfs(int node, vector<int>& used, vector<int>& topsort) {
    used[node] = 1;  // marcheaza nodul ca fiind vizitat
    // parcurg vecinii
    for (auto& neigh : adj[node]) {
        if (!used[neigh]) {
            dfs(neigh, used, topsort);
        }
    }

    // dupa ce am vizitat recursiv toti vecinii, adaugam
    // nodul la sortare
    topsort.push_back(node);
}

vector<int> solve_dfs() {
    // vectorul rezultat (in final contine o permutare pentru 1, 2, ..., n)
    vector<int> topsort;

    // used[node] = 1 daca node a fost deja vizitat, 0 altfel
    vector<int> used(m + 1, 0);

    // pentru fiecare nod
    for (int node = 1; node <= m; ++node) {
        // daca nodul este nevizitat, pornim o parcurgere
        if (!used[node]) {
            dfs(node, used, topsort);
        }
    }

    // rezultatul a fost obtinut in ordine inversa
    reverse(topsort.begin(), topsort.end());

    return topsort;
}

int main() {
    ifstream fin("curse.in");
    ofstream fout("curse.out");
    int i, j, n, a;
    fin >> n >> m >> a;
    int matrix[a][n];
    for (i = 0; i < a; i++) {
        for (j = 0; j < n; j++) {
            fin >> matrix[i][j];
        }
    }
    for (i = 0; i < a - 1; i++) {
        int j = 0;
        while (matrix[i][j] == matrix[i + 1][j] && j < n) {
            j++;
        }
        // adaugam arcul, deoarece am gasit
        // 2 elemente diferite
        adj[matrix[i][j]].push_back(matrix[i + 1][j]);
    }
    // extragem rezultatul obtinut in urma sortarii
    // topologice
    vector<int> toposort = solve_dfs();
    for (i = 0; i < toposort.size(); i++) {
        fout << toposort[i] << " ";
    }
    fout << endl;
    return 0;
}
