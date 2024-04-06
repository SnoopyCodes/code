#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n; cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) { cin >> v[i]; }
    ll ans = 0;
    map<int, int> sums;  //first is the sum; second is how many times it completes with another sum
    //if we start from b = n-3, c and d clearly are n-2 and n-1, but where is a?
    //a is from 0 to b-1
    //
    for (int b = n-3; b > 0; b--) {
        int c = b+1;
        for (int d = b+2; d < n; d++) {
            int diff = v[d] - v[c];
            sums[diff]++;
        }
        for (int a = 0; a < b; a++) {
            ans += sums[v[a]+v[b]];
        }
    }
    cout << ans << "\n";
//1.65 million for case 12
}