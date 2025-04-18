#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
const int MOD = 1e9 + 7;
const i64 INF = 4e18 + 7e9;

#define rep(i,s,e) for(auto i=s;i<e;i++)
#define rev(i,s,e) for(auto i=s;i>e;i--)
#define emp emplace
#define emb emplace_back
#define pob pop_back

void solve() {
    int N; cin >> N;
    string s; cin >> s;
    if (N == 1) { cout << -1 << "\n"; return; }
    //N^3 OK
    //uhh
    //oh i think i am bad then
    //do we ever have to insert characters
    //for which we have a surplus
    //022 -> 0122 -> 01022 -> 010122?
    //do you not just brute force with like linked list?
    //02122 -> 012122 -> 0102122 -> 01012122 -> 010102122
    //if its all of the same type then obviously failure
    //otherwise in between things we can always spawn either 0 or 1
    //01122 -> 011022 -> 0112022 -> 01120122 -> 011020122
    //greedy spam
    vector<int> seq(N);
    array<int, 3> f{};
    rep(i, 0, N) {
        if (s[i] == 'L') { f[0]++; seq[i] = 0; }
        if (s[i] == 'I') { f[1]++; seq[i] = 1; }
        if (s[i] == 'T') { f[2]++; seq[i] = 2; }
    }
    vector<int> ops;
    int OP = 2 * N;
    while (OP-- && (f[0] != f[1] || f[1] != f[2])) {
        bool done = false;
        rep(i, 0, N - 1) {
            if (seq[i] == seq[i + 1]) { continue; }
            int c = 3 - seq[i] - seq[i + 1];
            if (f[c] < f[seq[i]] || f[c] < f[seq[i + 1]]) {
                done = true;
                ops.emb(i);
                f[c]++;
                seq.emp(i + seq.begin() + 1, c);
                break;
            }
        }
        if (!done) {
            rep(i, 0, N - 1) {
                if (seq[i] == seq[i + 1]) { continue; }
                int c = 3 - seq[i] - seq[i + 1];
                done = true;
                ops.emb(i);
                f[c]++;
                seq.emp(i + seq.begin() + 1, c);
                break;
            }
        }
        if (!done) { cout << -1 << "\n"; return; }
        // cout << ops.back() << "\n";
        // rep(i, 0, N) {
        //     cout << seq[i] << " ";
        // }
        // cout << "\n";
        // cout << "\n";
        N++;
    }
    if (f[0] == f[1] && f[1] == f[2]) {
        cout << ops.size() << "\n";
        for (int x : ops) {
            cout << x + 1 << "\n";
        }
    }   else {
        cout << -1 << "\n";
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}