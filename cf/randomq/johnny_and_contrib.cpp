#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int, z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

int N;
mt<int> G;
vt<int> T;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int M; cin >> N >> M;
    G = mt<int>(N);
    T = vt<int>(N);
    //topo sort?
    //N things
    //we have N blogs, N topics??
    //so if the thing has 0 edges, we are going with 
    //1 1 1 1 1 1... spam
    //for each node, it can select up to the MEX of its neighbors selected?
    //we have to make a permutation in some way.
    //let's not spam sqrt stuff
    //deg(u) + 1 determines the maximum possible topic writable.
    //wait nvm this problem is a lot easier than i thought it would be.
    //cause i misread it
    //assign the order. we start from T[i] == 1 and move on from there
    //just do topo
    //why is this wrong?
    //we process layer by layer
    vt<int> need(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].add(v);
        G[v].add(u);
    }
    mt<int> in_d(N + 2);
    for (int i = 0; i < N; i++) {
        cin >> T[i]; T[i]--;
        in_d[T[i]].add(i);
    }
    bool ok = true;
    vt<int> order;
    for (int i = 0; i <= N; i++) {
        for (int u : in_d[i]) {
            if (need[u] != T[u]) { ok = false; }
            order.add(u);
            for (int v : G[u]) {
                if (need[v] == i) { need[v]++; }
            }
        }
    }
    if (!ok) { cout << -1 << "\n"; }
    else {
        for (int i = 0; i < N ;i++) {
            cout << order[i] + 1 << " \n"[i == N - 1];
        }
    }
}