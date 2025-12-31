#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define int long long
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, D; cin >> N >> D;
    int A, B; cin >> A >> B;
    vt<int> M(N);
    rep (i, 0, N) {
        cin >> M[i];
    }
    sort(begin(M), end(M));
    reverse(begin(M), end(M));
    int ans = 0;
    while (size(M) > A) {
        (ans += M.back() * M.back() % MOD) %= MOD;
        M.pop_back();
    }
    N = size(M);
    int s = M[0] - 1;
    auto orig = M;
    rep(i, 0, N) {
        M[i] += D;
    }
    int e = M[0];
    while (s + 1 < e) {
        int m = (s + e) / 2;
        int dec = B * D;
        rep(i, 0, N) {
            dec -= max({M[i] - m, 0ll});
        }
        if (dec >= 0) { e = m; }
        else { s = m; }
    }
    int amt = B * D;
    rep(i, 0, N) {
        amt -= max({M[i] - e, 0ll});
        M[i] = min(M[i], e);
    }

    //see if there's any way to max the constraint?
    //group things together by value.
    //pop elements that are already fully constrained
    //we only ever have a continuous segment of the array
    int i = 0, j = 0;
    int cval = M[j];
    while (true) {
        while (j < N && M[j] == cval) {
            j++;
        }
        int nval = orig[i];
        bool brk = false;

        auto eliminate = [&]() {
            int dec_all = amt / (j - i);
            int rem_sub_amt = amt % (j - i);
            (ans += rem_sub_amt * (cval - dec_all - 1) % MOD * (cval - dec_all - 1) % MOD) %= MOD;
            (ans += (j - i - rem_sub_amt) * (cval - dec_all) % MOD * (cval - dec_all) % MOD) %= MOD;
            rep(k, j, N) {
                (ans += M[k] * M[k] % MOD) %= MOD;
            }
            brk = true;
        };

        while (j == N || nval > M[j]) {
            int need = (j - i) * (cval - nval);
            if (amt > need) {
                amt -= need;
                cval = nval;
                (ans += cval * cval % MOD) %= MOD;
                i++;
                nval = orig[i];
            }   else {
                eliminate();
                break;
            }
        }
        if (brk) {
            break;
        }
        //decrease them all to M[j]
        int need = (j - i) * (cval - M[j]);
        if (amt > need) {
            amt -= need;
            cval = M[j];
        }   else {
            eliminate();
        }
        if (brk) {
            break;
        }
    }

    cout << ans << "\n";

}   