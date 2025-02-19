#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

void solve() {
    int N, Q; cin >> N >> Q;
    vec<int> portal(N);
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        int x = 0;
        for (char c : s) {
            if (c == 'B') { x += 4; }
            if (c == 'R') { x += 8; }
            if (c == 'G') { x += 2; }
            if (c == 'Y') { x += 1; }
        }
        portal[i] = x;
    }
    
    //now perform left sweep for closest of different colors
    vec<arr<int, 4>> cl(N, {-1, -1, -1, -1}), cr(N, {N, N, N, N});
    map<int, int> sweep;
    //actually wtf is happening why is this wrong
    //via pigeonhole we can only travel to one intermediate to get anywhere
    for (int i = 0; i < N; i++) {
        //get the two different colors
        for (int j = 0; j < 4; j++) {  //color we travel to
            if (portal[i] & 1 << j) { continue; }
            for (int k = 0; k < 4; k++) {
                if (!(portal[i] & 1 << k)) { continue; }
                int mask = (1 << j) + (1 << k);
                if (!sweep.count(mask)) { continue; }
                cl[i][j] = max(sweep[mask], cl[i][j]);
            }
        }
        sweep[portal[i]] = i;
    }
    sweep.clear();
    for (int i = N - 1; i > -1; i--) {
        for (int j = 0; j < 4; j++) {  //color we travel to
            if (portal[i] & 1 << j) { continue; }
            for (int k = 0; k < 4; k++) {  //color we have
                if (!(portal[i] & 1 << k)) { continue; }
                int mask = (1 << j) + (1 << k);
                if (!sweep.count(mask)) { continue; }
                cr[i][j] = min(sweep[mask], cr[i][j]);
            }
        }
        sweep[portal[i]] = i;
    }
    //now we should have the closest possible points of travel
    for (int q = 0; q < Q; q++) {
        int i, j; cin >> i >> j; i--; j--;
        if (i > j) { swap(i, j); }
        if (portal[i] & portal[j]) { cout << j - i << "\n"; continue; }
        int ans = INF;
        for (int k = 0; k < 4; k++) {
            if (portal[i] & 1 << k) {  //OK WTF
                if (cl[j][k] != -1) {
                    ans = min(ans, j - cl[j][k] + abs(i - cl[j][k]));
                }
                if (cr[j][k] != N) {
                    ans = min(ans, cr[j][k] - j + cr[j][k] - i);
                }
            }   else {
                if (cr[i][k] != N) {
                    ans = min(ans, cr[i][k] - i + abs(j - cr[i][k]));
                }
                if (cl[i][k] != -1) {
                    ans = min(ans, i - cl[i][k] + j - cl[i][k]);
                }
            }
        }
        if (ans != INF) { cout << ans << "\n"; }
        else { cout << -1 << "\n"; }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}