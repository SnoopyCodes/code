#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> reach;
vector<ll> mis(int l, int r) {  //all the independent sets
    vector<ll> res;
    for (int mask = 0; mask < 1 << r - l; mask++) {
        ll options = 0;
        for (int b = 0; b < r - l; b++) {
            if (mask & 1 << b) {  //we can reach all that this reaches
                options |= reach[b + l];
            }
        }
        bool valid = true;
        for (int b = 0; b < r - l; b++) {
            if (mask & 1 << b && options & 1LL << b + l) { valid = false; break; }
        }
        if (valid) { res.push_back((ll)mask << l); cout << mask << "\n";}
    }
    return res;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    reach.resize(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        reach[u] |= 1 << v;
        reach[v] |= 1 << u;
    }
    //meet in the middle probably works
    vector<ll> right = mis(N / 2, N);
    cout << right.size() << "\n";
    
}