#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> tree;
vector<int> dists;
vector<int> visited;
struct info {
    int nodes = 0, dist = 0;
};
info solve(int n) {
    info a;
    int dist = 0, ans = 0;
    if (visited[n] == 2) { return a; }
    visited[n]++;
    for (int i : tree[n]) {
        if (visited[i]) { continue; }
        info x = solve(i);
        a.nodes += x.nodes;
        a.dist += x.dist;
    }
    a.dist += a.nodes;
    dists[n] = a.dist;
    a.nodes++;

    if (visited[n] == 1) { return a; }  //just collecting for some other node
    //so first 0, 0
    //which becomes 1, 1
    //which goes to 3, 2 combined with 1, 1
    //4, 3 which goes to 8, 4
    //1, 1 w 1, 1 with 1, 1 with 1, 1 becomes
    //4, 4
    //4, 4 goes to 9, 4
    //we dont even need nodes what am i doing
    //wait what
    //we might actually need node dist and non-node dist
    //ans is  dist * 2 + 1? no its added together.?
    //how many times are we going to visit a node?
    //and then add all the under up
    visited[n] = 0;
    for (int i : tree[n]) {  //add the sum, which has been totaled, to all other nodes.

    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    tree.resize(n);
    dists.resize(n);
    visited.resize(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
        //in just O(N)?
        //bfs?
        //so in a tree, we know that for any node i to j, there is only one path
        //do we look at the tree diameter again?
        //so consider the tree diameter
        //we can basically keep a queue or stack or smth of nodes we've visited and their distances away from
        //for each node, the sum of its distances is the sum of all its adjacent nodes * 2?
        //each node has to go through twice:
        //once a node has finished getting its sum, declare its finished, adn then its surrounding nodes will take the sum
    }
}