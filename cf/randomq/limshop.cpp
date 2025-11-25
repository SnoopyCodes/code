#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  BIG = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;

template<class T, int D> struct mt : public vector<mt<T, D - 1>> {
    template<class...A> mt(int n = 0, A... r) : vector<mt<T, D - 1>>(n, mt<T, D - 1>(r...)) {} };
template<class T> struct mt<T, 1> : public vector<T> { using vector<T>::vector; };
template<class T> using vt = mt<T, 1>;

vt<int> get_inv_perm(vt<int> &P) {
    vt<int> inv(size(P));
    for (int i = 0; i < size(P); i++) {
        inv[P[i]] = i;
    }
    return inv;
}

void solve() {
    int N; cin >> N;
    vt<int> A(N), B(N);
    vt<int> V(N);
    for (int i = 0; i < N; i++) { cin >> V[i]; }
    for (int &u : A) { cin >> u; u--; }
    for (int &u : B) { cin >> u; u--; }
    auto invA = get_inv_perm(A), invB = get_inv_perm(B);
    /*
    consider N^2 solutions
    yeah iterate over a
    we can consider buying a_i or we can not
    by increasing b so that it gets there (or it doesnt, in which case impossible)
    *very* easy N^2

    dp[N]
    */

    mt<int, 2> dp(N + 1, N, INF);
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) { //consider whether to buy the ith for a
        //item i is position j in b
        //for the cases where it hasn't been bought by b, we can buy it
        //if we decide not to buy it, we need to move all b to j
        //which i guess is doable without segtree
        //
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}