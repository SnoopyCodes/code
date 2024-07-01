#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<ll>> friends;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M, Q; cin >> N >> M >> Q;
    friends.resize(N, vector<ll>(N, 1e9 * N));
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--;
        friends[a][b] = min(friends[a][b], (ll)c);
        friends[b][a] = min(friends[b][a], (ll)c);
    }
    for (int i = 0; i < N; i++) {
        friends[i][i] = 0;
    }
    //lesgo
    //so what is the idea
    //we want to use 3 triply nested loops and declare one of them as our intermediate?
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                friends[i][j] = min(friends[i][j], friends[i][k] + friends[k][j]);
            }
        }
    }
    for (int q = 0; q < Q; q++) {
        int a, b; cin >> a >> b; a--; b--;
        if (friends[a][b] == 1e9 * N) {
            cout << -1 << "\n";
        }   else {
            cout << friends[a][b] << "\n";
        }
    }
}