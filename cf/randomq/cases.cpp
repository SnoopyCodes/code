#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, C, K; cin >> N >> C >> K;
    string s; cin >> s;
    vector<int> v(N);
    vector<vector<int>> dists(C, vector<int>(C, -1));
    for (int i = 0; i < N; i++) {
        v[i] = s[i] - 'A';
    }
    vector<int> last_seen(C, -1);
    //we need to calculate for each character the furthest dist away another appears
    //  2 * 2e5 + 2 * 2e5 already
    // wtf is this
    // i dont understand
    // so we want the largest number that we can remove and still be valid
    // lets just try our brainless sol
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < C; j++) {
            if (last_seen[j] == -1 || j == v[i]) { continue; }
            dists[v[i]][j] = max(dists[v[i]][j], i - last_seen[j]);
            dists[j][v[i]] = dists[v[i]][j];
        }
        last_seen[v[i]] = i;
    }
    //
    //what we do now is nothing

    for (int mask = 0; mask < 1 << C; mask++) {
        
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //quite an interesting bitmask dp problem
    //the idea is that we need to iterate over all subsets
    //and find the smallest one that has a max dist from any other element
    //of at most k
    int T; cin >> T; while(T) { T--; solve(); }
}