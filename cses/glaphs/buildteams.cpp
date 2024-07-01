#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> friends;
vector<int> color;
bool firstdfsinforever(int v, int c) {
    if (color[v] && c != color[v]) { return false; }
    if (color[v]) { return true; }
    color[v] = c;
    c = 3 - c;
    for (int adj : friends[v]) {
        if (!firstdfsinforever(adj, c)) { return false; }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //evil
    int N, M; cin >> N >> M;
    friends.resize(N);
    color.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        friends[a].push_back(b);
        friends[b].push_back(a);
    }
    bool valid = true;
    for (int i = 0; i < N; i++) {
        if (!color[i]) {
            if (!firstdfsinforever(i, 1)) {
                valid = false; break;
            }
        }
    }
    if (valid) {
        for (int i = 0; i < N; i++) {
            cout << color[i];
            if (i < N - 1) { cout << " "; }
        }
        cout << "\n";
    }   else {
        cout << "IMPOSSIBLE" << "\n";
    }
    
}