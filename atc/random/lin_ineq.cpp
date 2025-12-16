#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 998244353;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
#define rep(i, a, b) for (auto i = a; i < (b); i++)
#define vi vt<int>

template<int MOD> struct mint {
	long v; mint(long _v = 0):v(_v % MOD) { v += (v < 0) * MOD; }
	#define fmo(o, c, z) friend mint operator o (mint a, mint b) { return a.v z c.v; }
	fmo(+, b, +) fmo(-, b, -) fmo(*, b, *) fmo(/, pow(b, MOD - 2), *)
	friend mint pow(mint x, long p) { return p ? pow(x * x, p / 2) * (p & 1 ? x : 1) : 1; }
	#define mo(o, z) mint& operator o (mint x) { return (*this) = (*this) z x; }
	mo(+=, +) mo(-=, -) mo(*=, *) mo(/=, /)
};
using mi = mint<MOD>;
//idk hwo to use this at all
int RT = 3;
void ntt(vector<mi>& a, bool inv) {
  int n = size(a);
  vector<mi> b(n);
  for (int i = n / 2; i; i /= 2, swap(a, b)) {
    mi w = pow(mi(RT),(MOD - 1) / n * i), m = 1;
    for (int j=0; j<n; j += 2 * i, m *= w) rep(k,0,i) {
      mi u = a[j + k], v = a[j + k + i] * m;
      b[j/2 + k] = u + v, b[j/2 + k + n/2] = u - v;
    }
  }
  if (inv) {
    reverse(1 + begin(a), end(a));
    mi z = 1 / mi(n); rep(i, 0, n) a[i] *= z;
  }
}

vector<mi> conv(vector<mi> a, vector<mi> b) {
  int s = size(a) + size(b) - 1, n = 1 << __lg(2 * s - 1);
  a.resize(n);
  ntt(a, 0);
  b.resize(n);
  ntt(b, 0);
  rep(i, 0, n) a[i] *= b[i];
  ntt(a, 1); a.resize(s);
  return a;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    long M; cin >> M;
    vi A(N);
    rep(i, 0, N) cin >> A[i];
    int K = N * *ranges::max_element(A);

    vt dp(2 * K, array<mi, 2>{});
    dp[0][0] = 1;
    vt<int> ways(K + 1);
    ways[0] = 1;
    rep(i, 0, N) {
        for (int j = K; j > A[i] - 1; j--) {
            (ways[j] += ways[j - A[i]]) %= MOD;
        }
    }
    
    //the dp state is very nice: it compresses previous states into only over/under
    int LOGM = __lg(M - 1) + 1;

    rep(b, 0, LOGM) {
        auto prev = dp;
        dp = vt(2 * K, array<mi, 2>{});
        //for this bit, we can choose some amount to yes!
        rep(i, 0, 2 * K) { //original sum
            rep(j, 0, K + 1) { //choose new sum to with
                //new dp is dp[j + i/2][bit stuff] += prev[i/2][bit stuff] * ways[j]
                int newsum = i / 2 + j;
                rep(over, 0, 2) {
                    if ((newsum & 1) == (M >> b & 1)) {
                        dp[newsum][over] += prev[i][over] * ways[j];
                    }   else {
                        dp[newsum][(M >> b & 1) < (newsum & 1)] += prev[i][over] * ways[j];
                    }
                }
            }
        }
    }

    cout << (dp[1][0] + dp[0][0]).v << "\n";
    
}