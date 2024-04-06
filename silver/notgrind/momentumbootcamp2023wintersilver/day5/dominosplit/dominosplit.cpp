#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> together;
vector<bool> visited;
int dist;
void valid(int i) {
    if (visited[i] == true) {  //return distance
        return;
    }
    visited[i] = true;
    dist++;
    for (int x : together[i]) {
        if (!visited[x])
        valid(x);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    int Q; cin >> Q;
    int total = 0;
    for (int q = 0; q < Q; q++) {
        int n; cin >> n;
        visited.clear(); visited.resize(n);
        together.clear(); together.resize(n);
        for (int i = 0 ; i < n; i++) {
            int a, b; cin >> a >> b;
            a--; b--;
            together[a].push_back(b);
            together[b].push_back(a);
        }
        bool good = true;
        for (int i = 0; i < n; i++) {
            if (together[i].size() > 2) { good = false; break; }  //cant have more than 2
            dist = 0;
            valid(i);
            if (dist % 2) { good = false; break; }
        }
        total += good;
    }
    cout << total << "\n";
}