#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;

const char NONE = '-';
const int INF = 1e9;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vec<vec<char>> con(N, vec<char>(N));
    vec<vec<int>> dist(N, vec<int>(N, INF));
    queue<arr<int, 2>> q;
    rep(i, N) {
        rep(j, N) {
            cin >> con[i][j];
            if (i != j && con[i][j] != NONE) {
                dist[i][j] = 1;
                q.push({i, j});
            }
        }
        dist[i][i] = 0;
        q.push({i, i});
    }
    //dense graph
    //either: start from a midpoint
    //or start from either end
    //midpoints are better because they favor dense graphs iirc
    //select a midpoint and bfs? uhhh
    //this does work if the palindrome is even length
    //however we need an odd length..
    while (!q.empty()) {
        auto [u, v] = q.front(); q.pop();
        //N^2 decide where to go
        rep(i, N) {  //go to here
            if (con[i][u] == NONE) { continue; }
            rep(j, N) {
                if (con[i][u] == con[v][j]) {
                    if (dist[u][v] + 2 < dist[i][j]) {
                        dist[i][j] = dist[u][v] + 2;
                        q.push({i, j});
                    }
                }
            }
        }
    }
    rep(i, N) {
        rep(j, N) {
            if (dist[i][j] != INF) {
                cout << dist[i][j];
            }   else {
                cout << -1;
            }
            cout << " \n"[j == N - 1];
        }
    }
}