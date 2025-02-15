#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    vec<bool> in(1001);
    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        in[x] = true;
    }
    vec<int> ot;
    for (int i = 1; i <= N; i++) {
        if (!in[i]) {
            ot.push_back(i);
        }
    }
    cout << ot.size() << "\n";
    for (int i = 0; i < ot.size(); i++) {
        cout << ot[i] << " \n"[i == ot.size() - 1];
    }
}