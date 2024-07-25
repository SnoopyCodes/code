#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, C, K;
    string s; cin >> s;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        v[i] = s[i] - 'A';
    }
    vector<int> last_seen(C, -1);
    //we need to calculate for each character the furthest dist away another appears
    //  2 * 2e5 + 2 * 2e5 already
    // 
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //quite an interesting bitmask dp problem
    //the idea is that we need to iterate over all subsets
    //and find the smallest one that has a max dist from any other element
    //of at most k
    int T; cin >> T; while(T) { T--; solve(); }
}