#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;
const int M = 19;

int N;
bool cangive[M][M];
int order[M][M], dp[M][1 << M], ways[1 << M], valid[1 << M];
void dfs(int u, int first, int bm) {
    bm |= 1 << u;
    if (cangive[u][first]) {
        //isnt this counting the # of ways?
        valid[bm]++;
    }
    for (int v = first + 1; v < N; v++) {
        if (cangive[u][v]) {
            if (bm >> v & 1) {

            }   else {
                dfs(v, first, bm);
            }
        }
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> order[i][j], order[i][j]--;
        }
    }

    for (int i = 0; i < N; i++) {
        valid[1 << i] = true;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) { continue; }
            //can i give to j? if position of i < position of j in order[j]
            int ii = -1, ji = -1;
            for (int k = 0; k < N; k++) {
                if (order[j][k] == i) { ii = k; }
                if (order[j][k] == j) { ji = k; }
            }
            
            cangive[i][j] = ii < ji;
        }
    }

    //this is brute force, pmo
    for (int i = 0; i < N; i++) {
        dfs(i, i, 0);
    }

    dp[0][0] = 1;

    for (int mask = 0; mask < 1 << N; mask++) {
        for (int subm = mask; subm != 0; subm = (subm - 1) & mask) {
            if (valid[subm]) {
                for (int amt = 0; amt < N; amt++) {
                    dp[amt + 1][mask] += dp[amt][mask ^ subm];
                }
            }
        }
    }
    
    int fac[19];
    fac[0] = 1;
    for (int i = 1; i <= N; i++) fac[i] = fac[i - 1] * i;
    for (int mask = 0; mask < 1 << N; mask++) {
        for (int amt = 0; amt <= N; amt++) {
            ways[mask] += dp[amt][mask] / fac[amt];
        }
    }
    
    int Q; cin >> Q;
    while (Q --> 0) {
        int mh = 0, mg = 0;
        string s; cin >> s;
        for (int i = 0; i < N; i++) {
            if (s[i] == 'H') {
                mh ^= 1 << i;
            }   else {
                mg ^= 1 << i;
            }
        }
        cout << ways[mh] * ways[mg] << "\n";
        
    }
}
/*
why is dp just so hard
*/