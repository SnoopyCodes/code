#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

#define rep(i,a,b) for(auto i=(a); i<(b); i++)

void solve() {
    int N; cin >> N;
    array<set<int>, 3> sets;
    int k = 0;
    vt<int> A(N);
    rep(i, 0, N) {
        cin >> A[i];
    }

    vt<ii<2>> ops;

    rep(i, 0, N) {
        sets[A[i]].insert(i);
    }

    //kmsksmkmskmskmskms
    auto op = [&](int u, int v) {
        ops.add({ u + 1, v + 1 });
        sets[A[u]].erase(u);
        sets[A[v]].erase(v);
        sets[A[u]].insert(v);
        sets[A[v]].insert(u);
        swap(A[u], A[v]);
    };

    rep(i, 0, size(sets[0])) {
        if (A[i] == 0) { continue; }
        if (A[i] == 1) {
            op(i, *sets[0].rbegin());
        }   else {
            op(i, *sets[1].rbegin());
            op(i, *sets[0].rbegin());
        }
    }
    rep(i, size(sets[0]), size(sets[0]) + size(sets[1])) {
        if (A[i] == 1) { continue; }
        if (A[i] == 2) {
            op(i, *sets[1].rbegin());
        }
    }
    
    cout << size(ops) << "\n";
    rep(i, 0, size(ops)) {
        cout << ops[i][0] << " " << ops[i][1] << "\n";
    }
    
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T-->0) solve();
}