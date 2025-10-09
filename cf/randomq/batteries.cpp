#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  BIG = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

int query(int u, int v) {
    cout << u + 1 << " " << v + 1 << endl;
    int x; cin >> x;
    return x;
}

void solve() {
    int N; cin >> N;
    vt<int> used(N);
    mt<bool> done(N, vt<bool>(N));
    auto cmp = [&](int u, int v) {
        return used[u] != used[v] ? used[u] < used[v] : u < v;
    };
    set<int, decltype(cmp)> S(cmp);
    for (int i = 0; i < N; i++) {
        S.insert(i);
    }
    while (true) {
        int u = *S.begin();
        int v = -1;
        for (int w : S) {
            if (!done[u][w] && u != w) {
                v = w;
                break;
            }
        }
        if (query(u, v)) {
            break;
        }
        done[u][v] = true;
        done[v][u] = true;
        S.erase(u);
        S.erase(v);
        used[u]++;
        used[v]++;
        S.insert(u);
        S.insert(v);
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}