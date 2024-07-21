#include <bits/stdc++.h>

using namespace std;
vector<vector<array<int, 2>>> observed;
int N;
vector<int> toposort;
bool valid(int g) {
    //idk
    toposort.clear();
    vector<int> in(N);
    for (int i = 0; i < N; i++) {
        for (const auto &[near, when] : observed[i]) {
            if (when <= g) {
                in[near]++;
            }
        }
    }
    priority_queue<int> pq;
    for (int i = 0; i < N; i++) {
        if (in[i] == 0) {
            pq.push(-i);
        }
    }
    while (!pq.empty()) {
        int v = -pq.top();
        toposort.push_back(v);
        pq.pop();
        for (const auto&[near, when] : observed[v]) {
            if (when <= g) {
                in[near]--;
                if (in[near] == 0) {
                    pq.push(-near);
                }
            }
        }
    }
    return toposort.size() == N;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("milkorder.in", "r",  stdin);
    freopen("milkorder.out", "w", stdout);
    int M; cin >> N >> M;
    observed.resize(N);
    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        int prev; cin >> prev; prev--;
        for (int j = 1; j < num; j++) {
            int x; cin >> x; x--;
            observed[prev].push_back({x, i});
            prev = x;
        }
    }
    // cout << "\n";
    // for (int i = 0; i < N; i++) {
    //     cout << i << "\n";
    //     for (auto const&[x, ob] : observed[i]) {
    //         cout << x << "_" << ob << " ";
    //     }
    //     cout << "\n";
    // }
    int s = -1, e = M;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        if (valid(m)) {
            s = m;
        }   else {
            e = m;
        }
    }
    valid(s);

    for (int i = 0; i < N; i++) {
        cout << toposort[i]+1 << " \n"[i == N - 1];
    }
}