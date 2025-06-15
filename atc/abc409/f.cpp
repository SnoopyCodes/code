#include <bits/stdc++.h>

using namespace std;

#define long long long
template<class T> using min_heap = std::priority_queue<T, vector<T>, std::greater<T>>;


long dist(array<int, 2> a, array<int, 2> b) {
    return abs(a[0] - b[0]) + abs(a[1] - b[1]);
}

struct DSU {
    int N;
    vector<int> root, size;
    DSU(int _N):N(_N), root(N), size(N, 1)
    { iota(root.begin(), root.end(), 0); }
    void add() {
        root.push_back(N);
        size.push_back(1);
        N++;
    }
    int find(int u) {
        if (root[u] != u) { root[u] = find(root[u]); }
        return root[u];
    }
    bool merge(int u, int v) {
        int ru = find(u);
        int rv = find(v);
        if (ru == rv) { return false; }
        if (size[ru] < size[rv]) { swap(ru, rv); }
        size[ru] += size[rv];
        root[rv] = ru;
        return true;
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    DSU cc(N);
    int ct = N;
    //brute force dsu?
    vector<array<int, 2>> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i][0] >> P[i][1];
    }
    min_heap<array<long, 3>> mh;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            mh.push({ dist(P[i], P[j]), i, j });
        }
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 1) {
            array<int, 2> p;
            cin >> p[0] >> p[1];
            P.push_back(p);
            for (int i = 0; i < N; i++) {
                mh.push({ dist(P[i], p), i, N });
            }
            N++;
            cc.add();
        }   else if (t == 2) {
            while (!mh.empty() && cc.find(mh.top()[1]) == cc.find(mh.top()[2])) {
                mh.pop();
            }
            if (!mh.empty()) {
                int d = mh.top()[0];
                cout << d << "\n";
                while (!mh.empty() && mh.top()[0] == d) {
                    auto [dd, u, v] = mh.top(); mh.pop();
                    ct -= cc.merge(u, v);
                }
            }   else {
                cout << -1 << "\n";
            }
        }   else {
            int u, v; cin >> u >> v; u--; v--;
            if (cc.find(u) == cc.find(v)) { cout << "Yes" << "\n"; }
            else { cout << "No" << "\n"; }
        }
    }
}