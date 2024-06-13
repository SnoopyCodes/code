#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<array<int, 2>>> flights;
vector<ll> dists;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int N, M; cin >> N >> M;
    flights.resize(N);
    dists.resize(N, LONG_LONG_MAX);
    priority_queue<array<ll, 2>> pq; //take the minimum cost flight
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        flights[a].push_back({b, c});
    }
    dists[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        int dest = pq.top()[1];
        if (-pq.top()[0] != dists[dest]) {
            pq.pop(); continue;
        }
        pq.pop();

        for (auto x : flights[dest]) {
            if (dists[x[0]] > dists[dest] + x[1]) {
                dists[x[0]] = dists[dest] + x[1];
                pq.push({-dists[x[0]], x[0]});
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << dists[i];
        if (i < N - 1) { cout << " "; }
    }
    //first we find hte minimum 
}