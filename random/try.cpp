#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

#define rep(i,s,e) for(auto i=s;i<e;i++)
#define am(x, y) ((((x) % MOD + (y) % MOD) % MOD + MOD) % MOD)

struct trie {
    array<trie*, 26> next{};
    bool end = false;
    void ins(string &w, int i) {
        if (i == w.size()) { end = true; return; }
        int c = w[i] - 97;
        if (!next[c]) { next[c] = new trie(); }
        next[c]->ins(w, i + 1);
    }
} root;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string w; cin >> w;
    int N = w.size();
    int K; cin >> K;
    rep(i, 0, K) {
        string s; cin >> s;
        root.ins(s, 0);
    }
    //dp[i] = number of ways to make up to i not including
    vector<int> dp(N + 1);
    dp[0] = 1;
    rep(i, 0, N) {
        if (!dp[i]) { continue; }
        trie *trav = &root;
        rep(j, i, N) {
            int c = w[j] - 97;
            if (!trav->next[c]) { break; }
            trav = trav->next[c];
            if (trav->end) { dp[j + 1] = am(dp[j + 1], dp[i]); }
        }
    }
    cout << dp[N] << "\n";
}