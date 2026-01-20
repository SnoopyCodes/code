#include <bits/stdc++.h>

using namespace std;
#define int long long
#define add push_back
const int MOD = 1e9 + 7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, D; cin >> N >> D;
    vt<int> p2(N + 1);
    p2[0] = 1;
    rep(i, 1, N + 1) p2[i] = p2[i - 1] * 2 % MOD;

    vt<ii<2>> cows(N);
    vt<int> campers, coaches;
    rep(i, 0, N) {
        cin >> cows[i][0] >> cows[i][1];
        if (cows[i][1] == 0) {
            campers.add(cows[i][0]);
        }   else {
            coaches.add(cows[i][0]);
        }
    }
    
    auto get = [&](int l, int r) {
        int ep = upper_bound(begin(campers), end(campers), r) - begin(campers);
        int sp = lower_bound(begin(campers), end(campers), l) - begin(campers);
        return ep - sp;
    };

    vt<int> dp(N + 1); //dp on # of coaches
    
    N = size(coaches);

    int r = N - 1;
    int camppt = (int) size(campers) - 1;
    int outres = 0;
    int pvqv = 0;
    int inq = 0;
    for (int i = N - 1; i > -1; i--) {
        //we need to find # of in between here and next
        while (camppt > -1 && campers[camppt] > D + coaches[i]) {
            camppt--;
        }
        int ct = 0;
        while (camppt > -1 && campers[camppt] >= coaches[i]) {
            ct++;
            camppt--;
        }

        while (i < r && coaches[r] - coaches[i] > D) {
            (outres += dp[r]) %= MOD;
            //-= p2[in between front and end of the queue] * this
            ((pvqv -= (p2.at(get(coaches[i + 1], coaches[r])) * dp[r]) % MOD) += MOD) %= MOD;
            r--;
        }
        
        int var = get(coaches[i], coaches[i] + D);
        dp[i] = p2[var] * (outres + 1) % MOD;
        pvqv *= p2[ct];
        (dp[i] += pvqv % MOD) %= MOD;
        (pvqv += dp[i]) %= MOD;
        //find the previous value of it
        //we have "previous queue value"
        //take "previous queue value" and then add previous dp value to it
        //multiply by 2^ct
        //how to pop back?
        //if r must back, then how do we update?
        //just pop away lmao
    }

    int ans = 0;
    rep(i, 0, N) {
        (ans += dp[i]) %= MOD;
    }
    cout << ans << "\n";
}