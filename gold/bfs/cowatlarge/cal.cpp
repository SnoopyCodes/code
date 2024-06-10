#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> tree;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("atlarge.in", "r", stdin);
    freopen("atlarge.out", "w", stdout);
    int N, K; cin >> N >> K; K--;
    tree.resize(N);
    //okay so we can run a bfs to figure out the distances?
    //wait so first the farmers must cover the closest
    //which means that if it were in a branch if the leaf is closer to branching point than bessie no 
    //other from the branching point will work
    //so for each branching point (adj > 2) take the minimum excuse me but is this not bfs or am i tripping
    //we should probably start from the leaves thouh
    //if we start a bfs from the leaves
    //query the stuff back
    //first bfs and declare branching points
    //something is wrong with our process
    //we are stating that there are more escape routes than acceptable
    //what test case would make us say we need more?
    //what why is this hard
    vector<bool> polices(N, true);  //earliest dist
    vector<int> lastbranch(N);
    vector<int> dists(N, -1);
    dists[K] = 0;
    lastbranch[K] = -1;
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    int ans = 0;
    queue<array<int, 3>> go; go.push({K, K, 0});
    while (!go.empty()) {
        auto v = go.front();
        go.pop();
        if (tree[v[0]].size() == 1) {  //
            //wait help how do i like
            //help
            int b = v[1];
            bool valid = true;
            while (b != -1) {
                //test the last branch
                if (!polices[b]) { valid = false; break; }
                if (dists[v[0]] - dists[b] <= dists[b]) {
                    polices[b] = false;
                }
                b = lastbranch[b];
            }
            ans += valid;
        }   else {
            //literally hlep wtf is this
            int branch = tree[v[0]].size() != 2 ? v[0] : v[1];
            for (int x : tree[v[0]]) {
                if (dists[x] != -1) { continue; }
                dists[x] = dists[v[0]] + 1;
                lastbranch[x] = branch;
                go.push({x, branch, dists[x]});
            }
        }
    }
    cout << ans << "\n";
}