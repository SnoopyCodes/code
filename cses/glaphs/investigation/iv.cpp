#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
struct City {
    bool visited = false;
    ll sp = 1e9 * 1e5, ways = 0;
    int minf = INT_MAX, maxf = 0;
    vector<array<int, 2>> flights;
};
vector<City> cities;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    cities.resize(N);

    for (int i = 0; i < M; i++) {
        int a, b, d; cin >> a >> b >> d; a--; b--;
        cities[a].flights.push_back({b, d});
    }
    cities[0].sp = 0, cities[0].ways = 1,
    cities[0].maxf = 0, cities[0].minf = 0;
    priority_queue<array<ll, 2>> pq;  //-dist, city
    pq.push({0, 0});
    while (!pq.empty()) {
        ll dist = -pq.top()[0];
        int city = pq.top()[1];
        pq.pop();
        if (dist != cities[city].sp || cities[city].visited) { continue; }
        cities[city].visited = true;
        //when do we add attributes?
        //we are multi counting the ways
        //someone help
        //when we come across something it is happening twice over
        //we don't really need that!
        for (auto const& [v, d] : cities[city].flights) {
            if (cities[v].sp > d + dist) {
                cities[v].sp = d + dist;
                cities[v].minf = cities[city].minf + 1;
                cities[v].maxf = cities[city].maxf + 1;
                cities[v].ways = cities[city].ways;
            }   else if (cities[v].sp == d + dist) {
                cities[v].minf = min(cities[v].minf, cities[city].minf + 1);
                cities[v].maxf = max(cities[v].maxf, cities[city].maxf + 1);
                cities[v].ways += cities[city].ways;
                cities[v].ways %= MOD;
            }   else { continue; }
            pq.push({-cities[v].sp, v});
        }
    }
    City goal = cities[N-1];
    cout << goal.sp << " " << goal.ways << " " << goal.minf << " " << goal.maxf;
}