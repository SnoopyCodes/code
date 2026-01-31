#include <bits/stdc++.h>

using namespace std;

#define int long long
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

const int L = 50;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    /*
    euclidean distance...
    just use prims, sorting by x-coordinate, 
    and only consider cows that have x-coord less than us OR <= 10 x away from us
    */

    vt<ii<2>> cows(N);
    for (int i =0 ; i < N; i++) cin >> cows[i][0] >> cows[i][1];
    sort(begin(cows), end(cows));
    vt<int> dist(N, 1e18);
    vt<bool> done(N);
    priority_queue<ii<2>> pq;
    dist[0] = 0;
    pq.push({ 0, 0 });
    /*
    stores { -dist, cow }
    */

    int cost = 0;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        d = -d;
        if (dist[u] != d) { continue; }
        cost += dist[u];
        done[u] = true;
        
        auto [x, y] = cows[u];
        for (int v = u - L; v <= u + L; v++) {
            if (v < 0 || v >= N || done[v]) { continue; }
            auto [a, b] = cows[v];
            if ((x - a) * (x - a) + (y - b) * (y - b) < dist[v]) {
                dist[v] = (x - a) * (x - a) + (y - b) * (y - b);
                pq.push({ -dist[v], v });
            }
        }
    }
    cout << cost << "\n";

}