#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

void solve() {
    int N; cin >> N;
    vec<int> A(N);
    map<int, int> freq;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        freq[A[i]]++;
    }
    //find maximize...
    //this means find a range [l, r] where 
    //+some values appear distinctly only in [l, r]
    //- the length of [l, r]
    //this can only ever be at max 0
    //we actually always have to find it
    //the score never goes down
    //find the longest contiguous subarray where it contains ONLY distinct elements
    //so each element appears only once in the entire array as well!
    int lst = -1;
    arr<int, 2> ans{0, -1};
    for (int i = 0; i < N; i++) {
        if (freq[A[i]] > 1) { lst = -1; continue; }
        if (lst == -1) { lst = i; }
        if (i + 1 - lst > ans[1] + 1 - ans[0]) {
            ans = {lst+1, i+1};
        }
    }
    if (ans[0] == 0 && ans[1] == -1) { cout << 0 << "\n"; }
    else
    cout << ans[0] << " " << ans[1] << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}