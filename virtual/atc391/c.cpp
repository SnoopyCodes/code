#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    int ans = 0;
    vec<int> in(N);
    vec<set<int>> nest(N);
    //does N log N + Q log N tle? hmm
    for (int i = 0; i < N; i++) {
        nest[i].insert(i);
        in[i] = i;
    }
    for (int q = 0; q < Q; q++) {
        int t; cin >> t;
        if (t == 2) {
            cout << ans << "\n";
        }   else {
            int p, h; cin >> p >> h; p--; h--;
            nest[in[p]].erase(p);
            if (nest[in[p]].size() == 1) { ans--; }
            in[p] = h;
            nest[h].insert(p);
            if (nest[h].size() == 2) { ans++; }
        }
    }
}