#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
using i64 = long long;
const i64 INF = 4e18 + 7e9;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    i64 M; cin >> M;
    vec<int> fin(N);
    vec<arr<int, 2>> swaps(K);
    vec<int> sim(N);
    vec<vec<arr<int, 2>>> seen(N);
    rep(i, N) {
        sim[i] = i;
        seen[i].push_back({0, i});
    }

    rep(i, K) {
        cin >> swaps[i][0] >> swaps[i][1]; swaps[i][0]--; swaps[i][1]--;
        seen[sim[swaps[i][0]]].push_back({i+1, swaps[i][1]});
        seen[sim[swaps[i][1]]].push_back({i+1, swaps[i][0]});
        swap(sim[swaps[i][0]], sim[swaps[i][1]]);
    }
    rep(i, N) {
        fin[sim[i]] = i;
    }
    
    vec<int> ans(N);
    vec<bool> visited(N);
    vec<int> begin(N);  //where does it begin in the path

    rep(i, N) {
        if (visited[i]) { continue; }
        int u = i;
        vec<arr<i64, 2>> path;
        vec<int> cyc;
        while (!visited[u]) {
            visited[u] = true;
            begin[u] = path.size();
            for (auto [t, v] : seen[u]) {
                path.push_back({t + (i64) cyc.size() * K, v});
            }
            cyc.push_back(u);
            u = fin[u];
        }
        map<int, int> m;
        int end = 0;
        rep(u, path.size()) {
            end = u;
            if (path[u][0] > M) { break; }
            m[path[u][1]]++;
        }
        ans[cyc[0]] = m.size();
        int j = 0;
        rep(k, 1, cyc.size()) {
            u = cyc[k];
            while (j < begin[u]) {
                m[path[j][1]]--;
                if (m[path[j][1]] == 0) {
                    m.erase(path[j][1]);
                }
                path.push_back({path[j][0] + (i64) cyc.size() * K, path[j][1]});
                j++;
            }
            while (end < path.size() && path[end][0] <= M + path[begin[u]][0]) {
                m[path[end][1]]++;
                end++;
            }
            ans[u] = m.size();
        }
    }
    rep(i, N) {
        cout << ans[i] << "\n";
    }
}