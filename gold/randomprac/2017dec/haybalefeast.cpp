#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("hayfeast.in", "r", stdin);
    freopen("hayfeast.out", "w", stdout);
    int N; cin >> N;
    ll M; cin >> M;
    //sliding window with 2p, clearly
    multiset<int> slide;
    vector<array<int, 2>> bales(N);
    ll cur = 0;
    int ans = 1e9;
    int del = 0;
    for (int i = 0; i < N; i++) {
        cin >> bales[i][0] >> bales[i][1];
        cur += bales[i][0];
        slide.insert(bales[i][1]);
        while (cur >= M) {
            ans = min(ans, *--slide.end());
            cur -= bales[del][0];
            slide.erase(slide.find(bales[del][1]));
            del++;
        }
    }
    cout << ans << "\n";
}