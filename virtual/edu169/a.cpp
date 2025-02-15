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
    vec<int> point(N);
    for (int i = 0; i < N; i++) {
        cin >> point[i];
    }
    //if there are 2 and they are not extremely close yes otherwise no
    if (N == 2 && point[1] - point[0] > 1 || N == 1) { cout << "YES" << "\n"; }
    else { cout << "NO" << "\n"; }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}