#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<int>> tree;
vector<bool> visited;
vector<ll> meredist;
vector<int> subnum;
vector<ll> total;
int N;
void init(int i) {
    for (int x : tree[i]) {
        if (visited[x]) { continue; }
        visited[x] = true;
        init(x);
        subnum[i] += subnum[x];
        meredist[i] += subnum[x] + meredist[x];
    }
    subnum[i]++;
}
//okay, now we need to traverse the same thing again, but this time we give distances
void add(int i, ll tot) {
    //for each of these nodes children, what we give them is parents sum + all the other childrens sum
    //for ourselves we just add tot to our meredist and thats it
    //tot already has all the other nodes to our single node
    total[i] = tot + meredist[i];
    for (int x : tree[i]) {
        if (visited[x]) { continue; }
        visited[x] = true;
        add(x, tot + N - subnum[x] + meredist[i] - meredist[x] - subnum[x]);  //scuffed formula but wtv
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    tree.resize(N);
    meredist.resize(N);
    subnum.resize(N);
    total.resize(N);
    visited.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    visited[0] = true;
    init(0);
    visited.clear();
    visited.resize(N);
    visited[0] = true;
    add(0, 0);
    for (int i = 0; i < N - 1; i++) {
        cout << total[i] << " ";
    }
    cout << total[N-1];
    //root tree arbitrarily
    //for each node the distances are: num nodes in 1st adj subtree + (mere dist to subtree)...num nodes in last adj subtree + (mere dist to subtree)
    //+ pardist + (N - subnum)

}