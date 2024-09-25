#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<array<int, 2>>> stations;
int N;
vector<ll> sp_standard(int start) {
    vector<ll> dists(N, 1e18);
    dists[start] = 0;
    priority_queue<array<ll, 2>> pq;
    pq.push({0, start});
    while (!pq.empty()) {
        ll d = -pq.top()[0];
        int u = pq.top()[1];
        pq.pop();
        if (dists[u] != d) { continue; }
        for (auto const&[v, c] : stations[u]) {
            if (dists[v] > d + c) {
                dists[v] = d + c;
                pq.push({-dists[v], v});
            }
        }
    }
    return dists;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int M; cin >> N >> M;
    stations.resize(N);
    vector<ll> shortest_u;
    vector<ll> shortest_v;
    int S, T; cin >> S >> T; S--; T--;
    int U, V; cin >> U >> V; U--; V--;
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        stations[a].push_back({b, c});
        stations[b].push_back({a, c});
    }
    shortest_u = sp_standard(U);
    shortest_v = sp_standard(V);
    // for (int i = 0; i < N; i++) {
    //     cout << i << " " << shortest_u[i] << " " << shortest_v[i] << "\n";
    // }
    // cout <<"\n";
    ll ans = shortest_u[V];

    auto sp_modded = [&] (int start, int end) {
        //we want to find for [end], the node that gets closest to v
        //and the one that gets closest to u
        //wtff this problem is amazing
        //{distance to u, distance to v}
        //we need to do it twice though-- one for 
        //mindist from u, and one for mindist from v
        vector<array<ll, 2>> dp(N);
        for (int i = 0; i < N; i++) {
            dp[i][0] = shortest_u[i];
            dp[i][1] = shortest_v[i];
        }
        vector<ll> dists(N, 1e18);
        priority_queue<array<ll, 2>> pq;
        dists[start] = 0;
        pq.push({ 0, start });
        while (!pq.empty()) {
            ll d = -pq.top()[0];
            int u = pq.top()[1];
            // cout << u << endl;
            // cout << d << endl;
            pq.pop();
            if (dists[u] != d) { continue; }
            for (auto const&[v, c] : stations[u]) {
                // cout << v << " " << c << "\n";
                if (dists[v] < d + c) { continue; }
                //i honestly dont understand this very well
                if (min(dp[u][0], shortest_u[v]) + min(dp[u][1], shortest_v[v]) < dp[v][0] + dp[v][1]) {
                    dp[v][0] = min(shortest_u[v], dp[u][0]);
                    dp[v][1] = min(shortest_v[v], dp[u][1]);
                }
                if (dists[v] > d + c) {
                    dists[v] = d + c;
                    dp[v][0] = min(shortest_u[v], dp[u][0]);
                    dp[v][1] = min(shortest_v[v], dp[u][1]);
                    pq.push({-dists[v], v});
                }
            }
            // cout << "\n";
        }
        
        // for (int i = 0; i < N; i++) {
        //     cout << dp[i][0] << " " << dp[i][1] << "\n";
        // }
        return dp[end][0] + dp[end][1];
    };
    ans = min(ans, sp_modded(S, T));
    // cout << "\n";
    ans = min(ans, sp_modded(T, S));
    cout << ans << "\n";
}