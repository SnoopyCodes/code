#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

void solve() {
    int l, r, i, k; cin >> l >> r >> i >> k;
    //f(x) gives # of values y in the range [0, x] : y === k (% 2^i)
    //answer = (r + 1 - l) - (f(r) - f(l - 1))
    auto f = [&](int n) {
        bool f = n == 3 && i == 1 && k == 2;
        //at each bit, if it is 1, then we can turn it off
        //and set all but the final i bits to whatever we want.
        //check edge cases
        int ans = 0;
        for (int b = 61; b >= i; b--) {
            if (n >> b & 1) {
                ans += (1LL << b - i);
            }
        }
        bool border = n == k;
        if (n == 43 && i < 6) {
            cout << i << " e " << k << " " << ans + border << "\n";
        }
        return ans + border;
    };


    int allxor = 0;
    //do allxor
    //g(x, b) gives ^ of values y in the range[0, x] : y >> b & 1
    auto g = [&](int n, int b) {
        if (b == 0) {
            return (int) (n % 4 == 1 || n % 4 == 2);
        }
        int rem = n % (1ll << b + 1);
        if (n >> b & 1) {
            return rem + 1 & 1;
        }
        return 0ll;
    };
    rep(b, 0, 61) {
        if (g(r, b) ^ g(l - 1, b)) {
            allxor ^= 1ll << b;
        }
    }

    int borexor = 0;
    if (f(r) - f(l - 1) & 1) {
        borexor += k;
    }
    rep(j, i, 61) {
        k += 1ll << j;
        i++;
        if (f(r) - f(l - 1) & 1) {
            cout << i << "\n";
            cout << "r " << f(r) << "\n";
            cout << "l - 1 " << f(l - 1) << "\n";
            borexor ^= 1ll << j;
        }
    }
    cout << borexor << "\n";
    cout << (allxor ^ borexor) << "\n";

    //screwed up
    //okay uhh
    //great fantastic
    //x != k mod 2^i
    //i mean first off get the xor sum of [l, r]
    //that is pretty easily doable (citation needed)
    //get the xor sum of uninteresting integers in the range
    //obviously, the last k bits are fixed.
    //we can obtain the frequency of them to determine if their 
    //bits are used in the final answer
    //actually, we can also do this for the later bits.
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T -->0) solve();
}