#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;
vector<array<ll, 2>> ans(1e6+1);
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ans[1][0] = 1;
    ans[1][1] = 1;
    for (int i = 2; i <= 1e6; i++) {
        //the ways for single tile ([0]) from previous [0] are
        //x4. then add the [1]
        //the ways for single tile [1] from previous [0] are
        //x1, and from previous [1] is also just [1]
        ans[i][0] = (ans[i-1][0] * 4 + ans[i-1][1]) % MOD;
        ans[i][1] = (ans[i-1][0] + 2 * ans[i-1][1]) % MOD;
    }
    int T; cin >> T; while (T) {
        T--;
        int N; cin >> N;
        cout << (ans[N][0] + ans[N][1]) % MOD << "\n";
    }
}   