#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ints = array<int, z>;
template<int z> using longs = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

void solve() {
    int H, W; cin >> H >> W;
    bool swp = H > W;
    vv<int> G(min(H, W), vt<int>(max(H, W)));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char c; cin >> c;
            (swp ? G[j][i] : G[i][j]) = (c == '.' ? 1 : -1);
        }
    }
    if (swp) { swap(H, W); }

    /*
    abuse sqrt. for each square we will know rect sum from 0,0
    we want for each (i, j) how many pairs (k, l) such that rect_sum(i, j, k, l)
    = 0
    fix top and bottom sides, and as we iterate right 
    for each square (i, j) we can find for each k 
    */
    long ans = 0;
    int A = H * W;
    vt<int> cnt(2 * A + 1);
    cnt[A]++;
    vv<int> cm(H + 1, vt<int>(W));
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++) {
            cm[j + 1][i] = cm[j][i] + G[j][i];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = i; j < H; j++) {
            int tot = 0;
            for (int k = 0; k < W; k++) {
                tot += cm[j + 1][k] - cm[i][k];
                // cout << i << " " << j << " " << k << " " << tot << "\n";
                    // if (cnt[A + tot]) {
                    //     cout << "e" << i << " " << j << " " << k << " " << cnt[A + tot] << "\n";
                    // }
                ans += cnt[A + tot];
                cnt[tot + A]++;
            }
            tot = 0;
            for (int k = 0; k < W; k++) {
                tot += cm[j + 1][k] - cm[i][k];
                cnt[tot + A]--;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}