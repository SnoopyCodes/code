#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 998244353;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T, int D> struct mt : public vt<mt<T, D - 1>> {
    template<class...A> mt(int n = 0, A... r) : vt<mt<T, D - 1>>(n, mt<T, D - 1>(r...)) {} };
template<class T> struct mt<T, 1> : public vt<T> {
    mt(int n = 0, const T &def = T()) : vt<T>(n, def) {} };

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    int D; cin >> D;
    vt<int> A(N);
    for (int &x : A) cin >> x;
    ranges::sort(A);

    vt<int> lim(N);
    long ans = 1;
    /* \forall i find lim_i*/ {
        int p = 0;
        for (int i = 0; i < N; i++) {
            while (p < N && A[p] <= D + A[i]) { p++; }
            lim[i] = p;
            (ans *= lim[i] - i) %= MOD;
        }
    }
    cout << ans << "\n";

    //

    
    
}