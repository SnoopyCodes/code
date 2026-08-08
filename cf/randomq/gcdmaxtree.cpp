#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

vt<int> fah;
int find(int u) {
    if (fah[u] != u) {
        fah[u] = find(fah[u]);
    }
    return fah[u];
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) { return; }
    if (rand() & 1) swap(u, v);
    fah[u] = fah[v];
}

vt<int> factors(int x) {
    vt<int> res;
    for (int i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (x / i != i) {
                res.push_back(x / i);
            }
        }
    }
    return res;
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vt<int> A(N);
    vt<vt<int>> facs(N);
    fah = vt<int>(N);
    iota(begin(fah), end(fah), 0);
    map<int, vt<int>> allf;
    int maxa = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        facs[i] = factors(A[i]);
        for (int f : facs[i]) {
            allf[f].push_back(i);
        }
        maxa = max(A[i], maxa);
    }

    vt<bool> exists(maxa+1);
    for (int x : A) {
        exists[x] = 1;
    }

    long long ans = 0;

    for (auto it = allf.rbegin(); it != allf.rend(); it++) {
        auto [f, vs] = *it;
        int fst = vs[0];
        for (int x : vs) {
            if (find(x) != find(fst)) {
                merge(x, fst);
                ans += f;
            }
        }
    }
    cout << ans << endl;

    //what is so hard about this?
    //gcd...
    //we are also connecting a set of nodes, notably. 
    //factors is bounded correctly, yes.
    //just linearly iterate what are we cooking.


    

}