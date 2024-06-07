#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
void solve()
{
    int ans = 0, n;
    n = 4e9;


    for (int i = 1; i * i <= n; i++)
    {
        int lim = n / i;
        ans += ((lim % mod) * ((lim + 1) % mod) / 2) % mod;
        ans %= mod;
        ans -= ((i % mod) * ((i + 1) % mod) / 2) % mod;
        ans += mod;
        ans %= mod;
        ans += (i * (lim - i + 1)) % mod;
        ans %= mod;
    }
    cout << ans << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout << setprecision(9);
    int tt = 1;
    // cin >> tt;
    for (int i = 1; i <= tt; i++)
    {
        // cout << "Case #" << i << ": ";
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
}