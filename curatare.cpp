#include <bits/stdc++.h>
using namespace std;
#define INF (1 << 30)
char adj[1000][1000];
int sol[4] = {0};
int min_dist = INF;
vector<vector<vector<int>>> bfsResults;
vector<pair<int, int>> start_points;
vector<pair<int, int>> dirty_spaces;

int compute(int nr) {
    int i, j, k;
    int distance;
    int max_dist = 0;
    int visited[4] = {0};
    for (i = 0; i < start_points.size(); i++) {
        distance = 0;
        vector<int> spaces;
        for (j = 0; j < nr; j++) {
            if (sol[j] == i) {
                spaces.push_back(j);
            }
        }
        int coord_x = start_points[i].first;
        int coord_y = start_points[i].second;
        for (k = 0; k < spaces.size(); k++) {
            // retine costul minim care se produce pentru ca
            // robotul i sa ajunga intr-un anumit punct murdar asociat lui
            int dist_min = INF;
            // retine index-ul spatiului murdar in care costul pentru
            // ca robotul sa ajunga in el este minim
            int min_index = -1;
            for (j = 0; j < spaces.size(); j++) {
                if (visited[spaces[j]] != 0) {
                    continue;
                }
                vector<vector<int>> res = bfsResults[spaces[j]];
                if (res[coord_x][coord_y] < dist_min) {
                    min_index = spaces[j];
                    dist_min = res[coord_x][coord_y];
                }
            }
            visited[min_index] = 1;
            distance += dist_min;
            coord_x = dirty_spaces[min_index].first;
            coord_y = dirty_spaces[min_index].second;
        }
        if (distance > max_dist) {
            max_dist = distance;
        }
    }
    return max_dist;
}

void backtracking(int step, int nr) {
    if (step == nr) {
        // extragem distanta obtinuta pentru solutia curenta
        int dist = compute(nr);
        if (dist < min_dist) {
            min_dist = dist;
        }
        return;
    }
    int i;
    for (i = 0; i < start_points.size(); i++) {
        sol[step] = i;
        backtracking(step + 1, nr);
    }
}

vector<vector<int>> calc_distances(int node_x, int node_y, int n, int m) {
    queue<pair<int, int>> q;
    vector<vector<int>> distances(n, vector<int>(m, -1));
    q.push({node_x, node_y});
    distances[node_x][node_y] = 0;
    while (!q.empty()) {
        auto first_elem = q.front();
        int x = first_elem.first;
        int y = first_elem.second;
        q.pop();
        if (x - 1 >= 0) {
            if (adj[x - 1][y] != 'X' && distances[x - 1][y] == -1) {
                distances[x - 1][y] = 1 + distances[x][y];
                q.push({x - 1, y});
            }
        }
        if (x + 1 < n) {
            if (adj[x + 1][y] != 'X' && distances[x + 1][y] == -1) {
                distances[x + 1][y] = 1 + distances[x][y];
                q.push({x + 1, y});
            }
        }
        if (y - 1 >= 0) {
            if (adj[x][y - 1] != 'X' && distances[x][y - 1] == -1) {
                distances[x][y - 1] = 1 + distances[x][y];
                q.push({x, y - 1});
            }
        }
        if (y + 1 < m) {
            if (adj[x][y + 1] != 'X' && distances[x][y + 1] == -1) {
                distances[x][y + 1] = 1 + distances[x][y];
                q.push({x, y + 1});
            }
        }
    }
    return distances;
}

int main() {
    int n, m;
    int i, j, k;
    ifstream fin("curatare.in");
    ofstream fout("curatare.out");
    fin >> n >> m;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            fin >> adj[i][j];
            if (adj[i][j] == 'R') {
                start_points.push_back({i, j});
            } else if (adj[i][j] == 'S') {
                dirty_spaces.push_back({i, j});
            }
        }
    }
    for (i = 0; i < dirty_spaces.size(); i++) {
        int coord_x = dirty_spaces[i].first;
        int coord_y = dirty_spaces[i].second;
        bfsResults.push_back(calc_distances(coord_x, coord_y, n, m));
    }
    backtracking(0, dirty_spaces.size());
    fout << min_dist << endl;
    return 0;
}
