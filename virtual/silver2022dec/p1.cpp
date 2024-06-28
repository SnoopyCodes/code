#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> hays;
ll goal;
vector<vector<array<ll, 2>>> orders;
vector<vector<int>> graph;
vector<int> in;
ll moves;
ll dfs(int v, int from) {
    ll amt = goal - hays[v];
    //how much we need
    //we need to put the earlier ones first
    //we need to start from the guy who 
    //okay so say its our turn
    //then we need some things to have been carried out before us
    for (int x : graph[v]) {
        if (x == from) { continue; }
        ll needs = dfs(x, v);
        if (needs < 0) {
            orders[x].push_back({-needs, v});
            in[v]++;
            moves++;
        }   else if (needs > 0) {
            orders[v].push_back({needs, x});
            in[x]++;
            moves++;
        }
        amt += needs;
    }
    return amt;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    in.resize(N);
    graph.resize(N);
    orders.resize(N);
    hays.resize(N);
    ll total = 0;
    for (int i = 0; i < N; i++) {
        cin >> hays[i];
        total += hays[i];
    }
    goal = total / N;
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    //okay so some hay bales
    //we want a certain goal okay
    //then we need to root the tree
    //then point from a certain node
    //we need a certain amount of stuff
    //wait we should form our orders after we get a result from the others
    //because the others should actually give back stuff explaining what they have
    //or how much they need to complete their order
    //so we should return the order we want
    dfs(0, -1);
    cout << moves << endl;
    queue<int> q;
    for (int i = 0; i < N; i++) {
        if (in[i] == 0) { q.push(i); }
    }
    while (!q.empty()) {
        int b = q.front();
        q.pop();
        for (auto const&[val, v] : orders[b]) {
            cout << b+1 << " " << v+1 << " " << val << "\n";
            hays[b] -= val;
            hays[v] += val;
            in[v]--;
            if (in[v] == 0) { q.push(v); }
        }
    }
    //okay the problem is definitely in our ordering
    //so we should direct each edge
    //and then afterwards we must choose the edge
    //okay its not toposort
    //hmmmmmm
    //really
    //its all ordering wtf
    //
}