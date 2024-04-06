#include <bits/stdc++.h>

using namespace std;
vector<int> pots;
vector<vector<int>> rooms;
vector<int> leaves;  //how many leaves are under it
int leafs = 0;
int use[100000];
int dfs(int i, int from) {
    for (int x : rooms[i]) {
        if (x != from) {
            leaves[i] += dfs(x, i);
        }
    }
    if (rooms[i].size() == 1 && from != -1) { leaves[i] = 1; }  //it is a leaf
    return leaves[i];
}
int real(int i, int from) {
    int used = 0;
    for (int x : rooms[i]) {
        if (x != from) {
            used += real(x, i);
        }
    }
    used += use[i];
    return min(used, leaves[i]);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("r", "in.txt", stdin);
    int N; cin >> N;
    pots.resize(N);
    rooms.resize(N);
    leaves.resize(N);
    cout << "\n";
    for (int i = 0; i < N; i++) {
        cin >> pots[i];
        pots[i]--;
        cout << pots[i] << "\n";
    }
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        rooms[a].push_back(b);
        rooms[b].push_back(a);
    }
    cout << "hi" << "\n";
    leafs = dfs(0, -1);
    cout << "\n";
    cout << leafs << "\n";
    cout << "\n";
    for (int i = 0; i < leafs; i++) {
        cout << pots[i] << "\n";
        use[pots[i]]++;
        //cout << use[pots[i]] << "\n";
    }
    for (int i = 0; i < N; i++) {
        // cout << use[i] << "\n";
    }
    cout << use[0] << "\n";
    int a = real(0, -1);
    cout << a << "\n";
}