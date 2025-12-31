#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


#include <bits/stdc++.h>
 
using namespace std;
 
#define add push_back
const int  MOD = 1e9  +    7;
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;
 
#define rep(i,a,b) for (auto i=a; i<(b); i++)
 
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
 
struct chash {
	// any random-ish large odd number will do
	const uint64_t C = uint64_t(2e18 * 3.141592653589) + 71;
	// random 32-bit number
	const uint32_t RANDOM = chrono::steady_clock::now().time_since_epoch().count();
	size_t operator()(uint64_t x) const {
		// see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
		return __builtin_bswap64((x ^ RANDOM) * C);
	}
};
 
template<typename T> using gset = gp_hash_table<T, null_type, chash>;


void solve() {
    int N, M; cin >> N >> M;
    map<int, int> m;
    vt<int> A(N); rep(i, 0, N) cin >> A[i], m[A[i]]++;
    map<int, vt<int>> mm;
    vt<ii<2>> flatten;
    for (auto [v, f] : m) {
        mm[f].add(v);
        flatten.add({ v, f });
    }
 
    vt<int> freq;
    vt<vt<int>> wf;
    for (auto [f, vs] : mm) {
        freq.add(f);
        ranges::reverse(vs);
        wf.add(vs);
    }
 
 
    gset<int64_t> ban;
    auto enc = [](int x, int y) {
        return (int64_t) x * MOD + y;
    };
    rep(i, 0, M) {
        int x, y; cin >> x >> y;
        ban.insert(enc(x, y));
    }
 
    int64_t best = 0;
 
    rep(i, 0, size(freq)) {
 //slow
        rep(j, i, size(freq)) {
            rep(k, 0, size(wf[i])) {
                int x = wf[i][k];
                int xf = freq[i];
                bool done = false;
                rep(l, 0, size(wf[j])) {
                    int y = wf[j][l];
                    int yf = freq[j];
                    if (x == y || ban.find(enc(min(x, y), max(x, y ))) != ban.end()) { continue; }
                    best = max(best, (int64_t) (x + y) * (xf + yf));
                    done = true;
                    break;
                }
            }
        }
 
    }
 
    cout << best << "\n";
 
}
 
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve(); 
}
