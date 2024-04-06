#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<int> roads[100000];
string cows;
bool visited[100000];
int types[100000];
void dfs(int i, char m, int mark) {
    if (visited[i]) { return; }
    visited[i] = true;
    types[i] = mark;
    for (int x : roads[i]) {
        if (cows[x] != m) { continue; }
        dfs(x, m, mark);
    }
}
//okay what do we do
//if we go with connected components
//how do we mark them
//maybe just with an integer- if they have the same integer they must be of the same connected component!
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("milkvisits.in", "r", stdin);
    freopen("milkvisits.out", "w", stdout);
    int N, M; cin >> N >> M;
    cin >> cows;
    for (int i =0 ; i < N-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) { continue; }
        dfs(i, cows[i], i+1);
    }
//okay so arbitrarily choose a node to do
//and then from any other node to any other node if it goes through that one all the values can be derived
//but if it doesnt then what can we do
//OR
//we could find all the connected components!
//and then just mark them!
//brilliant!
    string ans;
    for (int q = 0; q < M; q++) {
        int a, b; cin >> a >> b;
        a--; b--;
        string type; cin >> type;
        if (types[a] == types[b] && cows[a] != type[0]) { ans += "0"; }
        else { ans += "1"; }
    }
    cout << ans << "\n";
//O(N^2) for precomputing all map values and answering each query.
}