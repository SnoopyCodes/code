#include <bits/stdc++.h>

using namespace std;

vector<array<int, 2>> trav;
vector<bool> visited;
vector<bool> in_path;
long long ans = 0;

//we really dont need a dfs for a while loop do we
int head = -1, mine = 1e9 + 1;
void dfs(int u) {
    int v = trav[u][0];
    visited[u] = true;
    if (in_path[v]) {
        head = v;
        mine = trav[u][1];
    }   else if (!visited[v]) {
        in_path[u] = true;
        dfs(v);
        in_path[u] = false;
        if (head != -1) {
            mine = min(mine, trav[u][1]);
            if (u == head) { head = -1; }
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    trav.resize(N);
    in_path.resize(N), visited.resize(N);
    //very wow
    //for non cycle
    //wait what about for chains
    //and then for each cycle, choose the least value
    //very simple problem
    //actually no all functional graph problems arebad
    //if we have more than one child, only allow
    //the largest aggregate sum to go
    //no its not aggregate sum its like
    //largest radj edge lmao
    //wait you can literlaly add all the edges wtf am i cooking
    //the only time we don't add everything is the cycles
    //if we find a cycle, find minimum value in cycle and delete it
    //thats it
    //then topologically sort
    //QWAIT ITS NOT EVEN GIVE AN ORDER LOL
    
    for (int i = 0; i < N; i++) {
        cin >> trav[i][0] >> trav[i][1]; trav[i][0]--;
        ans += trav[i][1];
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs(i);
            if (mine != 1e9 + 1) { ans -= mine; mine = 1e9 + 1; }
        }
    }
    cout << ans << "\n";
}