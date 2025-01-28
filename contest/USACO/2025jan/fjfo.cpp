#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>

#define rat order_of_key
#define at find_by_order

using namespace __gnu_pbds;

template <class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define long int64_t

void solve() {
    long N, M; cin >> N >> M;
    vector<long> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        v[i] %= M;
    }
    iset<array<long, 2>> is;
    for (int i = 0; i < N; i++) {
        is.insert({v[i], i});
    }
    long med = (*is.at(N / 2))[0];
    long best = 1e18, cur = 0;
    long ans = 0;
    for (auto [x, y] : is) {
        cur += abs(x - med);
    }
    best = cur;
    for (int i = 1; i < N; i++) {
        auto [a, b] = (*is.begin());
        is.erase(is.begin());
        cur -= med - a;
        a += M;
        is.insert({a, b});
        long newmed = (*is.at(N / 2))[0];
        long diff = newmed - med;
        cur += a - newmed;
        int less = (N) / 2;
        cur += less * diff;
        med = newmed;
        cur -= (N - 1 - less) * diff;
        if (cur < best) { ans = i; best = cur; }
    }
    cout << best << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}