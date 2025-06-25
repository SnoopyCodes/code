#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;

#define long long long

vector<int> seg;
int N;

void update(int i, int val) {
    seg[i + N] = val;
    for (i = (i + N) / 2; i > 0; i /= 2) {
        seg[i] = max(seg[2 * i], seg[2 * i + 1]);
    }
}
int query(int l, int r) {
    int res = -N;
    l = max(0, l);
    r = min(r, N);
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { res = max(res, seg[l++]); }
        if (r & 1) { res = max(res, seg[--r]); }
    }
    return res;
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int D, R; std::cin >> N >> D >> R;
    //H is a permutation of thing
    //ok take inverse permutation
    //then you can move to elements if |i - j| <= R
    //this might be easier
    //it might be sliding window or smth
    //only look at the past D elements
    //i think consider segtree for max
    vector<int> dist(N);  //position of height basically
    for (int i = 0; i < N; i++) {
        int x; std::cin >> x; x--;
        dist[x] = i;
    }
    seg.resize(2 * N, -N);  //contains max for in position R
    int best = 0;
    vector<int> bst(N);
    for (int i = 0; i < N; i++) {
        if (i >= D) { update(dist[i - D], bst[i - D]); }
        int cur = query(dist[i] - R, dist[i] + R + 1) + 1;
        best = max(best, cur);
        bst[i] = max(cur, 0);
    }
    std::cout << best << "\n";
}