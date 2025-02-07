#include <bits/stdc++.h>

#define vec vector
#define arr array
#define long int64_t

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vec<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int Q; cin >> Q;
    vec<long> help(N + 1), pf(N + 1), layers(N + 1), triangle(N + 2);
    long total = 0;
    for (int i = 1; i < N + 1; i++) {
        help[i] = help[i - 1] + N - i + 1;
        pf[i] = pf[i - 1] + A[i - 1];
        total += pf[i];
    }
    layers[1] = total;
    triangle[N] = pf[N];
    for (int i = N - 1; i > 0; i--) {
        triangle[i] = triangle[i+1] + pf[i];
    }
    for (int i = 2; i <= N; i++) {
        layers[i] = layers[i-1];
        total -= (long) (A[i-2]) * (N - (i - 2));
        layers[i] += total;
    }
    auto get_inds = [&](long x) {
        int s = 0, e = N + 1;
        while (s + 1 < e) {
            int m = (s + e) / 2;
            long hm = help[m];
            if (hm >= x) { e = m; }
            else { s = m; }
        }
        return arr<long, 2>{s, x - help[s]};
    };
    auto calc = [&](arr<long, 2> a) {
        auto [layer, idx] = a;
        long res = 0;
        res += layers[layer];
        idx += layer;
        if (layer == 0 && idx == 0) { return 0LL; }
        long diff = layers[layer + 1] - layers[layer];
        res += diff - triangle[idx+1] + pf[layer] * (N - idx);
        return res;
    };
    for (int q = 0; q < Q; q++) {
        long l, r; cin >> l >> r;
        auto la = get_inds(l-1), ra = get_inds(r);
        cout << calc(ra) - calc(la) << "\n";
    }
}