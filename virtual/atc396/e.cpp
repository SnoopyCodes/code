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

vec<vec<arr<int, 2>>> con;
vec<int> fin;
vec<bool> visited;
stack<int> st;
i64 delta = 0;
bool stop = false;
void dfs(int u, int b, bool c) {  //cur, par, bit, color
    if (bool(fin[u] & 1 << b) != c) {
        fin[u] ^= 1 << b;
    }
    delta += fin[u] & 1 << b;
    st.push(u);
    visited[u] = true;
    for (auto [v, w] : con[u]) {
        bool has = w & 1 << b;
        if (visited[v]) {  //must match
            if (bool((fin[u] & 1 << b) ^ (fin[v] & 1 << b)) != has) {
                stop = true;
                return;
            }
        }   else {
            dfs(v, b, has ^ c);
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    con.resize(N), fin.resize(N), visited.resize(N, false);
    rep(i, M) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        con[u].push_back({v, w});
        con[v].push_back({u, w});
    }
    rep(i, N) {
        if (visited[i]) { continue; }
        rep(b, -30) {
            delta = 0;
            dfs(i, b, 0);
            if (stop) {
                cout << -1 << "\n"; return 0;
            }
            i64 r1 = delta;
            while (!st.empty()) {
                visited[st.top()] = false;
                st.pop();
            }
            delta = 0;
            dfs(i, b, 1);
            if (delta > r1) {
                while (!st.empty()) {
                    visited[st.top()] = false;
                    st.pop();
                }
                dfs(i, b, 0);
            }
            if (b > 0)
            while (!st.empty()) {
                visited[st.top()] = false;
                st.pop();
            }
        }
        while (!st.empty()) {
            st.pop();
        }
    }
    rep(i, N) {
        cout << fin[i] << " \n"[i == N - 1];
    }
}