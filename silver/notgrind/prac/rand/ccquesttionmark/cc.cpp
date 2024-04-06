#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<bool> visited;
set<int> banned;
vector<set<int>> dontvisit;
int n;
int dfs(int i) {
    if (visited[i]) { return 0; }
    visited[i] = true;
    int size = 1;
    set<int> remove;
    for (auto it = banned.begin(); it != banned.end(); it++) {
        if (dontvisit[i].find(*it) == dontvisit[i].end()) {  //if we have a banned number that they do not
            remove.insert(*it);
        }
    }
    for (auto& x : remove) {
        banned.erase(x);
    }
    for (auto &x : remove) {
        size += dfs(x);
    }
    return size;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int m; cin >> n >> m;
    visited.resize(n);
    dontvisit.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        dontvisit[a].insert(b);
        dontvisit[b].insert(a);
    }
    for (int i = 0; i < n; i++) { banned.insert(i); }
    // for (int i = 0; i < n; i++) {
    //     cout << i << ": ";
    //     for (auto &x : dontvisit[i]) {
    //         cout << x << " ";
    //     }
    //     cout << "\n";
    // }
    //take the very first what?
    multiset<int> sizes;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { sizes.insert(dfs(i)); }
    }
    cout << sizes.size() << "\n";
    for (auto &x : sizes) {
        cout << x << " ";
    }
    //so linked together ok
    //the overall size of the graph, however, is still a normal problem
    //this is good
    //it is impossible to compile the things between stuff
    //can we check if 0 connects to which components in a certain amount of time?
    //okay time limited.
    //okay maybe we do the thing where we try and add edges to our thing
    //like we have a visited boolean array right and then we try and add other edges to our graph
    //so first we add all the ones that are connected to our start
    //and then try and add the rest because as long as the rest aren't banned from all of our nodes then they can join

    //we only need try the nodes that are unbanned by our newest node...
    //keep a set of the numbers that we have banned, and when we add a node
    //check through their banned and if we have something they dont we can add that rq
    //this really does feel like mst
}