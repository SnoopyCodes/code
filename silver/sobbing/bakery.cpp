#include <bits/stdc++.h>

using namespace std;
using ll = long long;
struct bf {
    ll w;
    int c, m;
};
vector<bf> bfs;
bool spend(int g, int N, int C, int M) {
    /*
    x <= (w - m * (C - g))/(c - m)
    x + y <= X + Y - c

    */
    int minc = max(1, C - g), maxc = (C);
    for (auto f : bfs) {
        
    }

    return minc <= maxc;
}
void solve() {
    int N, C, M; cin >> N >> C >> M;
    bfs.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> bfs[i].c >> bfs[i].m >> bfs[i].w;
    }
    //we need to ensure that
    //bfs[i].c * C + bfs[i].m * M <= bfs[i].w for all i
    //we can probably binary search on the minimum cost
    int s = -1, e = C + M;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        //if spend, 
        if (spend(m, N, C, M)) { e = m; }
        else { s = m; }
    }
    cout << e << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}