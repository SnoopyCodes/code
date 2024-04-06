#include <bits/stdc++.h>

using namespace std;

struct Node{
    vector<int> nodes;
};
vector<Node> nodes;
vector<bool> visited;
int dist(int x) {
    if (visited[x]) { return 0; }
    visited[x] = true;
    int dist1 = 0;
    int dist2 = 0;
    for (int i : nodes[x].nodes) {
        int distance = dist(i) + 1;
        if (distance > dist1) { dist1 = distance; }
        else if (distance > dist2) { dist2 = distance; }
    }
    if (x == 0) { cout << dist1; }
    return dist1 + dist2;
}
int main() {
    //from leaf node to other leaf node- can we start from any leaf node? idts
    //find the root.?
    //then from the root, run a recursion to check dists
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N;
    cin >> N;
    nodes.resize(N);
    visited.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        nodes[a].nodes.push_back(b);
        nodes[b].nodes.push_back(a);
    }
    cout << dist(0);
}