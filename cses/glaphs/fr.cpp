#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct City {
    multiset<ll> leastcost;  //max size k
    vector<array<int, 2>> adj;  //city, cost
};
vector<City> cities;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int N, M, K; cin >> N >> M >> K;
    cities.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c; a--; b--;
        cities[a].adj.push_back({b, c});
    }
    cities[0].leastcost.insert(0);
    priority_queue<array<ll, 2>> pq;  //cost, city
    pq.push({0, 0});
    while (!pq.empty()) {
        ll dist = -pq.top()[0], v = pq.top()[1];
        pq.pop();
        if (!cities[v].leastcost.count(dist)) { continue; }
        for (auto const& [city, cost] : cities[v].adj) {
            if (cities[city].leastcost.size() < K) {
                cities[city].leastcost.insert(dist + cost);
                pq.push({-(dist + cost), city});
            }   else if (*(--cities[city].leastcost.end()) > dist + cost) {
                cities[city].leastcost.erase(--cities[city].leastcost.end());
                cities[city].leastcost.insert(dist + cost);
                pq.push({-(dist + cost), city});
            }
        }
    }
    for (ll x : cities[N-1].leastcost) {
        cout << x << " ";
    }
    cout << "\n";

}