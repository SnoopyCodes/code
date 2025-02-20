#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

void solve() {
    string s; cin >> s;
    int N = s.size();
    vec<int> block(4);
    rep(i, 4) {
        cin >> block[i];
    }
    vec<vec<bool>> A;
    int cnt = -1;
    arr<int, 2> f{};
    rep(i, N) {
        if ((i == 0 || s[i] == s[i-1]) && (i == N - 1 || s[i] == s[i+1])) {
            if (s[i] == 'A') { block[0]--; }
            else { block[1]--; }
        }   else {
            if (i == 0 || s[i] == s[i-1]) {
                A.push_back({});
                cnt++;
            }
            f[s[i] == 'B']++;
            A[cnt].push_back(s[i] == 'B');
        }
    }
    //now for the hard part: matching ab and ba
    //uhh
    //our goal is to use as many ab and ba as possible
    //abbaabbaabbaabbaab
    //consecutive letters are now a forced subdivision
    //we are solving now sequences of alternating letters
    //assert that frequency of a's and b's are the same
    //now.. we need optimal positioning
    //if length is odd, we have choices
    //if not, are we cooked?
    //we need to find x "ab" pairs and y "ba" pairs
    //
    if (f[0] > block[0] + block[2] + block[3]) { cout << "NO" << "\n"; return; }
    if (f[1] > block[1] + block[2] + block[3]) { cout << "NO" << "\n"; return; }
    // rep(i, A.size()) {
    //     rep(j, A[i].size()) {
    //         cout << A[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // rep(i, 4) {
    //     cout << block[i] << " ";
    // }
    // cout << "\n";

    rep(i, 4) {
        if (block[i] < 0) { cout << "NO" << "\n"; return; }
    }

    cout << "YES" << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}