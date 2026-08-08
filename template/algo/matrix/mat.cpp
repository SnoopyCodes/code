#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

//integer representation of rational cause fuck double precision

template<int MOD> struct mint {
	long v; mint(long _v = 0):v(_v % MOD) { v += (v < 0) * MOD; }
	#define fmo(o, c, z) friend mint operator o (mint a, mint b) { return a.v z c.v; }
	fmo(+, b, +) fmo(-, b, -) fmo(*, b, *) fmo(/, pow(b, MOD - 2), *)
	friend mint pow(mint x, long p) { return p ? pow(x * x, p / 2) * (p & 1 ? x : 1) : 1; }
	#define mo(o, z) mint& operator o (mint x) { return (*this) = (*this) z x; }
	mo(+=, +) mo(-=, -) mo(*=, *) mo(/=, /)
};
using T = mint<int(1e9 + 7)>;
#undef fmo
#undef mo

template<int z> using vec = array<T, z>;
template<int z> using sq = array<array<T, z>, z>;
template<int n, int m> using mat = array<array<T, m>, n>;

template<int n> inline T operator*(vec<n> a, vec<n> b) {
    T res;
    for (int i = 0; i < n; i++) {
        res += a[i] * b[i];
    }
    return res;
}


template<int n, int m> mat<m, n> inline transpose(mat<m, n> a) {
    mat<m, n> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[j][i] = a[i][j];
        }
    }
    return res;
}

//doesn't work :(
template<int n, int sz_a, int sz_b> mat<sz_a, sz_b> operator*(mat<sz_a, n> a, mat<n, sz_b> b) {
    mat<sz_a, sz_b> res;
    mat<sz_b, n> b_t = transpose(b);
    for (int i = 0; i < sz_a; i++) {
        for (int j = 0; j < sz_b; j++) {
            a[i][j] = a[i] * b_t[j];
        }
    }
    return res;
}



/*
for each of the rows i \in (1,n):
    eliminate the i-1st var.
what is back-substitution?

first assume there is a solution.
*/
template<int n> vec<n> Ax_eq_b(sq<n> A, vec<n> b) {
    vec<n> x, piv;
    for (int i = 1; i < n; i++) {
        //find first nonzero
        int p = -1;
        for (int j = 0; j < n; j++) {
            if (A[i][j] != 0) {
                p = j;
                break;
            }
        }
        //

    }
}

constexpr int N = 10;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    sq<N> a{};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            a[i][j] = rand() % 32;
            cout << a[i][j].v << " ";
        }
        cout << "\n";
    }


}