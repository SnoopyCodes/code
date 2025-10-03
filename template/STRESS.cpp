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



// ----------------- First Implementation -----------------

struct DSU {
    vector<int> par, size;
    long pairs = 0;
    DSU(int N): par(N), size(N) { while (N--) par[N] = N; }
    int find(int u) {
        if (par[u] != u) { par[u] = find(par[u]); }
        return par[u];
    }
    void add(int u) {
        u = find(u);
        pairs += size[u];
        size[u]++;
    }
    bool unite(int u, int v) {
        int ru = find(u), rv = find(v);
        if (ru == rv) { return false; }
        pairs -= (long) size[ru] * (size[ru] - 1) / 2;
        pairs -= (long) size[rv] * (size[rv] - 1) / 2;
        size[ru] += size[rv];
        pairs += (long) size[ru] * (size[ru] - 1) / 2;
        par[rv] = ru;
        return true;
    }
};

void solve() {
    int N, M; cin >> N >> M;
    vt<bool> type(N);
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        type[i] = c == '1';
    }
    mt<int> G(N);
    DSU cc(N);
    while (M--) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].add(v);
        G[v].add(u);
    }
    for (int i = 0; i < N; i++) {
        if (type[i]) {
            for (int v : G[i]) {
                if (v > i) { cc.unite(v, i); }
            }
        }
    }
    vt<long> ans(N);
    for (int u = N - 1; u > -1; u--) {
        cc.add(u);
        for (int v : G[u]) {
            if (u < v) { cc.unite(u, v); }
        }
        ans[u] = cc.pairs;
    }
    for (long x : ans) {
        cout << x << "\n";
    }
}


// ----------------- Second Implementation -----------------
//brute force

void solve2() {
    int N, M; cin >> N >> M;
    vt<bool> type(N);
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        type[i] = c == '1';
    }
    vt<set<int>> G(N);
    while (M--) {
        int u, v; cin >> u >> v; u--; v--;
        G[u].insert(v);
        G[v].insert(u);
    }
    
    for (int t = 0; t < N; t++) {
        int ct = 0;
        vt<bool> vis(N);
        vt<int> q(N);
        int s = 0, e = 0;
        for (int i = t; i < N; i++) {
            if (vis[i]) { continue; }
            int cur = 1;
            q[e++] = i;
            vis[i] = true;
            while (s < e) {
                int u = q[s++];
                for (int v : G[u]) {
                    if (!vis[v] && v > t) {
                        cur++;
                        q[e++] = v;
                        vis[v] = true;
                    }
                }
            }
            ct += cur * (cur - 1) / 2;
        }
        cout << ct << "\n";
        if (type[t]) {
            auto jit = G[t].begin();
            while (jit != G[t].end()) {
                auto kit = jit;
                kit++;
                for (; kit != G[t].end(); kit++) {
                    G[*jit].insert(*kit);
                    G[*kit].insert(*jit);
                }
                jit++;
            }
        }
        G[t].clear();
    }

}
 
// ----------------- Test Case Generator -----------------
string generateTestCase() {
    //write to oss
    //MODIFY
    ostringstream oss;
    // cout << "GENERATING" << endl;
    int N = 5, M = 4;
    oss << N << " " << M << endl;
    for (int i = 0; i < N; i++) {
        oss << (rand() % 2);
    }
    oss << "\n";
    for (int i = 0; i < M; i++) {
        int u = rand() % N + 1;
        int v = rand() % N + 1;
        while (u == v) { v = rand() % N + 1; }
        oss << u << " " << v << "\n";
    }
    return oss.str();
}
 
// ----------------- Helpers to Run a Solve Function -----------------
string runSolve(function<void()> solveFunc, const string &testInput) {
    // Save the original stream buffers.
    streambuf* origCin  = cin.rdbuf();
    streambuf* origCout = cout.rdbuf();
 
    // Redirect cin and cout.
    istringstream iss(testInput);
    ostringstream oss;
    cin.rdbuf(iss.rdbuf());
    cout.rdbuf(oss.rdbuf());
 
    // Run the provided solve function.
    solveFunc();
 
    // Restore original stream buffers.
    cin.rdbuf(origCin);
    cout.rdbuf(origCout);
 
    return oss.str();
}
 
// ----------------- Main Stress-Testing Loop -----------------
int main() {
    srand(time(NULL));
    //MODIFY
    int stressTests = 10000;
    for (int i = 1; i <= stressTests; i++) {
        string test = generateTestCase();
        string out2 = runSolve(solve2, test);
        string out1 = runSolve(solve, test);
        if (out1 != out2) {
            cout << "Mismatch found on test case #" << i << ":\n";
            cout << "Test case input:\n" << test << "\n";
            cout << "Output from solve:\n" << out1 << "\n";
            cout << "Output should be:\n" << out2 << "\n";
            return 0;
        }
    }
    cout << "All stress tests passed.\n";
    return 0;
}
