#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> v(N);
    vector<ll> pfx(N + 1);
    ll total = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        total += v[i];
        pfx[i+1] = v[i] + pfx[i];
    }
    if (total % 3 != 0) { cout << 0 << "\n"; return 0; }
    ll target = total / 3;
    //how do we find number of subarrays with this sum?
    //isnt it like we consider the number of places where the prefix sum ends up the same
    //then we want to see whether a certain thing exists or not
    //actually lets prefix sums then
    //then we need to see for each prefix sum if there exists a prefix sum in front which is target more
    //good. good.
    //am i stupid?
    int cnt = 0;  //how many times does 2 * target appear?
    ll ans = 0;
    for (int i = N - 1; i > 0; i--) {
        if (pfx[i] == target) { ans += cnt; }
        if (pfx[i] == 2 * target) { cnt++; }
    }
    cout << ans << "\n";
}