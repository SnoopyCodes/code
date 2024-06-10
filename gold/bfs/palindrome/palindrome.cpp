#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> graph;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //where to even try?
    //we can try just directly testing all the different lengths
    //base our bfs around the vertex traveling at 1
    //then it will contain a number of vertices for which we could be at right now (fulfilling the palindrome)
    //we should also not try the same vertex pairs twice!
    int N, M; cin >> N >> M;
    graph.resize(N, vector<vector<int>>(26));
    //use standard graph representation for now
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        char c; cin >> c;
        a--; b--;
        int p = c - 97;
        graph[a][p].push_back(b);
        graph[b][p].push_back(a);
    }
    //the nodes it may go to
    vector<vector<int>> dists(N, vector<int>(N));
    vector<vector<bool>> visited(N, vector<bool>(N));
    queue<array<int, 2>> q;
    q.push({0, N - 1});
    visited[0][N-1] = true;
    int mn = INT_MAX;
    while (!q.empty()) {
        auto info = q.front();
        q.pop();
        if (info[0] == info[1]) {
            mn = min(mn, dists[info[0]][info[1]]);
        }
        //our goal here is to find for our adjacent edges which ones have the same character
        for (int c = 0; c < 26; c++) {
            for (auto u : graph[info[0]][c]) {
                for (auto v : graph[info[1]][c]) {
                    if (!visited[u][v]) {
                        if (u == info[1] && v == info[0]) {
                            mn = min(dists[info[0]][info[1]] + 1, mn);
                        }
                        visited[u][v] = true;
                        dists[u][v] = 2 + dists[info[0]][info[1]];
                        q.push({u, v});
                    }
                }
            }
        }
    }
    cout << (mn == INT_MAX ? -1 : mn) << "\n";
}