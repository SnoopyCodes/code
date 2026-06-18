#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vt<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for_each(begin(B), end(B), [](auto &u) { cin >> u; }); //ts so tuff
    /*
    sqrt decomposition!
    consider values of (i mod j)?
    for values of j <= sqrt(M), we can brute force?
    for values of j > sqrt(M), idrk man its like a pyramid.
    did i just bs?
    we fix j, obviously.
    there are < sqrt(max) distinct values of i mod j.
    
    how do we obtain for some i the # of distinct modulus it can form?

    calculate triangular sum
    wait this is so tuff??
    */
}