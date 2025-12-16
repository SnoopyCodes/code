#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  BIG = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

template<int MOD> struct mint {
	long v; mint(long _v = 0):v(_v % MOD) { v += (v < 0) * MOD; }
	#define fmo(o, z) friend mint operator o (mint a, mint b) { return z; }
	fmo(+, a.v + b.v) fmo(-, a.v - b.v) fmo(*, a.v * b.v) fmo(/, a * pow(b, MOD - 2))
	friend mint pow(mint x, long p) { return p ? pow(x * x, p / 2) * (p & 1 ? x : 1) : 1; }
	#undef fmo
	#define mo(o, z) mint& operator o (mint x) { return (*this) = (*this) z x; }
	mo(+=, +) mo(-=, -) mo(*=, *) mo(/=, /)
	#undef mo
};
using mi = mint<int(1e9 + 7)>;

vector<mi> fax, p2;

void spit_fax(int N) {
	fax = vector<mi>(N + 1);
	fax[0] = 1;
    for (int i = 1; i <= N; i++) {
        fax[i] = fax[i-1] * i;
    }
}

void prec_2(int N) {
    p2 = vt<mi>(N + 1);
    p2[0] = 1;
    for (int i = 1; i <= N; i++) {
        p2[i] = p2[i - 1] * 2;
    }
}

void solve() {
    int N; cin >> N; N++;
    vt<int> P(N);
    for (int &u : P) { cin >> u; }
    int unset = 0;
    vt<bool> done(N);
    for (int i = 1; i < N; i++) {
        if (P[i] >= N) { cout << 0 << "\n"; return; }
        if (P[i] > -1 && P[P[i]] > -1 && P[P[i]] != i) { cout << 0 << "\n"; return; }
        if (P[i] > -1) {
            if (P[i] > 0) {
                if (done[P[i]]) {
                    cout << 0 << "\n";
                    return;
                }
                done[P[i]] = true;
            }
        }   else {
            unset++;
        }
    }
    for (int i = 1; i < N; i++) {
        if (done[i] && P[i] == -1) {
            unset--;
        }
    }
    bool haslast = !done[N - 1];
    //how do we deal with special case haslast?
    //what's the usual formula?
    //for k pairs, ans += 2^(unset - 2 * k) * unset! / 2^k / (unset - 2k)!
    //suppose last is not in a pair:
    //ans -= 2^(unset - 1 - 2k) * (unset - 1)! / 2^k / (unset - 1 - 2k)!
    mi ans = 0;
    for (int k = 0; 2 * k < unset; k++) {
        ans += p2[unset - 2 * k] * fax[unset] / p2[k] / fax[unset - 2 * k] / fax[k];
        if (haslast) {
            ans -= p2[unset - 1 - 2 * k] * fax[unset - 1] / p2[k] / fax[unset - 1 - 2 * k] / fax[k];
        }
    }
    if (unset % 2 == 0) {
        ans += fax[unset] / p2[unset / 2] / fax[unset / 2];
    }
    cout << ans.v << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    spit_fax(4e5);
    prec_2(4e5);
    int T; cin >> T; while(T--) { solve(); }
}