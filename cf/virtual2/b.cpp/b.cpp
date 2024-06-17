#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, F, K; cin >> N >> F >> K; F--; K--;
    vector<array<int, 2>> cubes(N);
    for (int i = 0; i < N; i++) {
        cin >> cubes[i][0];
        cubes[i][1] = i;
    }
    sort(cubes.begin(), cubes.end());
    reverse(cubes.begin(), cubes.end());
    int newi = 0;
    int lastsame = 0;
    for (int i = 0; i < N; i++) {
        if (cubes[i][1] == F) {
            newi = i;
            lastsame = i;
            while (lastsame < N && cubes[lastsame][0] == cubes[newi][0]) {
                lastsame++;
            }
            lastsame--;
            break;
        }
    }
    if (cubes[K][0] == cubes[newi][0] && lastsame > K) { cout << "MAYBE" << "\n"; }
    else if (K >= newi) { cout << "YES" << "\n"; }
    else {
        cout << "NO" << "\n";
    }
    
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}