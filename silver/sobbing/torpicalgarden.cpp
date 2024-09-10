#include <bits/stdc++.h>

using namespace std;
//best 2 edges
vector<array<int, 2>> gardens;
vector<int> res;
void add(int u, int v) {  //add v to u
    if (gardens[u][0] == -1) { gardens[u][0] = v; }
    else if (gardens[u][1] == -1) { gardens[u][1] = v; }
}
int dfs(int u, int from) {
    if (res[u] != -1 && from != gardens[u][0]) { return res[u]; }
    int v = gardens[u][0];
    bool change = from == gardens[u][0] && gardens[u][1] != -1;
    if (change) { v = gardens[u][1]; }
    int dist = dfs(v, u);
    if (!change) { res[u] = dist; }
    return dist + 1;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //fujii kaze
    //N <= 1.5e5
    //M <= 1.5e5
    //G 2000..
    //TL:5 s
    //each trail is the one that matters
    int N, M, P; cin >> N >> M >> P; P--;
    gardens.resize(N, {-1, -1});
    res.resize(N, -1);
    //this is like also online query bc each affects the next
    //wait nvm not really online query
    //i think
    //if we can offline query and then find the second most beautiful trail for each one
    //i think this is fine
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        add(b, a);
        add(a, b);
    }
    int Q; cin >> Q;
    vector<int> groups(Q);
    for (int i = 0; i < Q; i++) {
        cin >> groups[i];
    }
    //uhhhh wait
    //lets not worry about offline query lets worry about solving one thing first
    //basically, every single node can only go to 2 places
    //therefore create a like result array for every node
    //ok no
    //there is at most one cycle that we wish to reach
    //if we can reach that then its valid
    //do i even do this..
    for (int i = 0; i < N; i++) {
        if (res[i] == -1) { dfs(i, -1); }
    }
}