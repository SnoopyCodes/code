#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;

void solve() {
    int N, M, Q; cin >> N >> M >> Q;
    vector<int> A(N), B(M);
    vector<int> inv_P(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i]; A[i]--;
        inv_P[A[i]] = i;
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i]; B[i]--;
    }
    //ok
    //that did hella not work
    //use these sets
    //we have an order suppose
    //containing { slide, person }
    //count the persons and ensure that each is after the other
    vector<std::set<int>> at(N);
    std::map<int, int> order;
    int bad = 0;
    auto answer = [&]() { cout << (bad == 0 && order.begin()->second == A[0] ? "YA\n" : "TIDAK\n"); };
    auto ok = [&](int i, int j) {
        return inv_P[i] + 1 == inv_P[j];
    };
    auto upd = [&](int s, int t, bool rem) {
        int above = -1, less = -1;
        order.erase(s);
        if (order.upper_bound(s) != order.end()) {
            above = (*order.upper_bound(s)).second;
            if (!rem) { bad += !ok(t, above); }
            else { bad -= !ok(t, above); }
        }
        if (!order.empty() && (*--order.upper_bound(s)).first < s) {
            less = (*--order.upper_bound(s)).second;
            if (!rem) { bad += !ok(less, t); }
            else { bad -= !ok(less, t); }
        }
        if (above != -1 && less != -1) {
            if (!rem) { bad -= !ok(less, above); }
            else { bad += !ok(less, above); }
        }
        if (!rem) { order[s] = t; }
    };
    for (int i = 0; i < M; i++) {
        at[B[i]].insert(i);
        if (at[B[i]].size() == 1) {
            upd(i, B[i], false);
        }
    }
    answer();
    for (int q = 0; q < Q; q++) {
        int s, t; cin >> s >> t; s--; t--;
        int o = B[s];
        B[s] = t;
        at[o].erase(s);
        if (order.count(s)) {
            upd(s, o, true);
            if (at[o].size()) {
                upd(*at[o].begin(), o, false);
            }
        }
        if (at[t].empty() || s < *at[t].begin()) {
            if (!at[t].empty()) { upd(*at[t].begin(), t, true); }
            upd(s, t, false);
        }
        at[t].insert(s);
        answer();
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}