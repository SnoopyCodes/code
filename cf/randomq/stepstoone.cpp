#include <bits/stdc++.h>

using namespace std;
#define int long long
#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

int qp(int x, int p = MOD - 2) { return p ? 1ll*(p & 1 ? x : 1) * qp(1ll*x * x % MOD, p / 2) % MOD : 1; }

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    int M; cin >> M;
    //reduce all numbers to subsets of their coprime
    vt<vt<int>> prime_facs(M + 1);
    vt<int> coprimeify(M + 1, 1);
    vt<int> cnt(M + 1), era_cnt(M + 1);
    rep(i, 2, M + 1) {
        if (size(prime_facs[i])) { continue; }
        for (int j = i; j <= M; j += i) {
            prime_facs[j].add(i);
        }
    }
    rep(i, 1, M + 1) {
        for (int x : prime_facs[i]) {
            coprimeify[i] *= x;
        }
        cnt[coprimeify[i]]++;
    }


    rep(i, 2, M + 1) {
        for (int j = i; j <= M; j+= i) {
            era_cnt[i] += cnt[j];
        }
    }

    int ans = 0;
    vt<int> exp(M + 1);
    exp[1] = 1;
    rep(i, 2, M + 1) {
        int B = size(prime_facs[i]);
        vt<int> ways(1 << B);
        ways[0] = M;
        auto get = [&](int x) { //value of a mask
            int res = 1;
            rep(b, 0, B) {
                if (x >> b & 1) {
                    res *= prime_facs[i][b];
                }
            }
            return res;
        };

        for (int mask = (1 << B) - 1; mask > -1; mask--) {
            int val = get(mask);
            //https://codeforces.com/blog/entry/73818
            for (int overm = mask; overm < 1 << B; overm = (overm + 1) | mask) {
                int overval = get(overm);
                int d = __builtin_popcount(overm) - __builtin_popcount(mask);
                if (d & 1) {
                    ways[mask] -= era_cnt[overval];
                }   else {
                    ways[mask] += era_cnt[overval];
                }
            }
            //yay! we did it!
            if (val != i) { (exp[i] += ways[mask] * exp[val] % MOD) %= MOD; }
        }
        (exp[i] += M) %= MOD;

        (exp[i] *= qp(M - ways[(1 << B) - 1])) %= MOD;
        
    }
    int sum = 0;
    
    rep(i, 1, M + 1) {
        (sum += exp[i] * cnt[i] % MOD) %= MOD;
    }
    (sum *= qp(M)) %= MOD;
    cout << sum << "\n";
}