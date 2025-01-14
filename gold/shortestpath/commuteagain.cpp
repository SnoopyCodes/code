#include <bits/stdc++.h>
#define vec vector
#define long int64_t
using namespace std;

int N, S, T;
vec<vec<array<int, 2>>> rails;
vec<long> cost, ucost, vcost;

bool cmp (int u, int v) {
    return cost[u] != cost[v] ? cost[u] < cost[v] : u < v;
};

void dijkstra(int source) {
    cost.clear(); cost.resize(N, 1e18);
	cost[source] = 0;
    set<int, decltype(cmp)> s(cmp);
	s.insert(source);
	while (!s.empty()) {
		int u = *s.begin();
		s.erase(s.begin());
		for (auto [v, c] : rails[u]) {
			if (c + cost[u] < cost[v]) {
				s.erase(v);
				cost[v] = c + cost[u];
				s.insert(v);
			}
		}
	}
}

long dpdijkstra(bool change) {
    if (change) { swap(S, T); }
    vec<long> uclose(N, 1e18), vclose(N, 1e18);
    for (int i = 0; i < N; i++) {
        uclose[i] = ucost[i];
        vclose[i] = vcost[i];
    }
	cost.clear(); cost.resize(N, 1e18);
	cost[S] = 0;
    set<int, decltype(cmp)> s(cmp);
	s.insert(S);
	while (!s.empty()) {
		int u = *s.begin();
		s.erase(s.begin());
		for (auto [v, c] : rails[u]) {
            if (c + cost[u] > cost[v]) { continue; }
            //okay what tf happened
            //why does it just become min min and its fine
            //
            //if its the first time we can put on both
            //if its the second time onwards we have to be more careful
            //holy crap graph dp is tough, be careful!
			if (c + cost[u] < cost[v]) {
				s.erase(v);
				cost[v] = c + cost[u];
				uclose[v] = min(ucost[v], uclose[u]);
				vclose[v] = min(vcost[v], vclose[u]);
				s.insert(v);
			}
			if (min(ucost[v], uclose[u]) + min(vcost[v], vclose[u]) < uclose[v] + vclose[v]) {
				uclose[v] = min(ucost[v], uclose[u]);
				vclose[v] = min(vcost[v], vclose[u]);
			}
		}
	}
    return uclose[T] + vclose[T];
}

int main() {
	cin.tie(0) -> sync_with_stdio(0);
	int M; cin >> N >> M;
	cin >> S >> T; S--; T--;
	int U, V; cin >> U >> V; U--; V--;
	rails.resize(N);
	for (int i = 0; i < M; i++) {
		int u, v, c; cin >> u >> v >> c; u--; v--;
		rails[u].push_back({v, c});
		rails[v].push_back({u, c});
	}
    dijkstra(U);
	ucost = cost; 
    dijkstra(V);
    vcost = cost;
    long ans = ucost[V];
    ans = min(ans, dpdijkstra(false));
    ans = min(ans, dpdijkstra(true));
    cout << ans << endl;
}