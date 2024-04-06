#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> tree;
vector<bool> visited;
array<int, 2> diameter(int x) {  //[0] is longest path, [1] is longest sum
    visited[x] = true;
    array<int, 2> a{0, 0};
    array<int, 2> best{0, 0};
    for (int adj : tree[x]) {
        if (!visited[adj]) {
            auto test = diameter(adj);
            a[1] = max(a[1], test[1]);
            if (test[0] > best[0]) {
                best[1] = best[0];
                best[0] = test[0];
            }   else if (test[0] > best[1]) {
                best[1] = test[0];
            }
        }
    }
    a[1] = max(a[1], best[0] + best[1]);
    a[0] = max(best[0], best[1]) + 1;
    return a;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    tree.resize(N);
    visited.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    auto arr = diameter(0);
    cout << max(arr[0]-1, arr[1]);
}