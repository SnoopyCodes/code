#include <bits/stdc++.h>

using namespace std;
#define int long long
#define add push_back
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

#define rep(i,a,b) for (auto i=a; i<(b); i++)

void solve() {
    int N; cin >> N;
    using vi = vt<int>;
    vi A(N), B(N);
    int ans = 0;
    rep(i,0,N) cin >> A[i], ans += A[i] * A[i] * (N - 2);
    rep(i,0,N) cin >> B[i], ans += B[i] * B[i] * (N - 2);

    /*
    so for each element x x^2 is counted N - 1 times
    this leaves xy \forall x \in A \forall y != x \in A
    notation is a bit off but wtv

    key part i guess is that it is x * (sum(A) - x) \forall x \in A
    therefore summing across all x we get sum(A)^2 - \sigma x^2 \forall x \in A
    
    so final is x^2 * (N - 2) \forall x + sum(A)^2 + sum(B)^2
    we must minimize sum(A)^2 + sum(B)^2, or in other words, make them as close to each other
    in sum as possible- pretty trivial.
    */



}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}