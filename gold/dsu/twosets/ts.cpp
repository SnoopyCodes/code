#include <bits/stdc++.h>

using namespace std;

vector<int> dsu;
int find(int v) {
    if (v == dsu[v]) { return v; }
    dsu[v] = find(dsu[v]);
    return dsu[v];
}
void unite(int u, int v) {
    if (u == v) { return; }
    if (rand() % 2) {
        dsu[v] = u;
    }   else {
        dsu[u] = v;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, A, B; cin >> N >> A >> B;
    //all numbers are distinct
    //we can link them together then sort by number of adj edges
    //why dont we run a 0-1 bfs based on 
    //we can draw an edge to stuff
    //help how do we not troll this too hard
    //at most each number has 2 links
    //how do we use dsu what
    //wait ok what
    //helppp
    //ok so when we join stuff together what are we doing 
    //it is bad if there is ???
    //oh ok so thats how it checks
    //okay then
    //2 5 3 4 (7, 8)
    //wait so every cc has live in the same one?
    //why does this make it so that it 
    //suppose that yes a cc exists so that some may only exist within the first, and some within only the second
    //7, 9
    //1, 6, 3,  8?
    //1-7 -> 7, 3-4 -> 7
    //so if a vertex does exist that only lives within the second then it will definitely take away one which is 
    //allowed to ?
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        dsu[i] = i;
    }
    vector<bool> icanA(N), icanB(N);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < N; i++) {
        if (binary_search(nums.begin(), nums.end(), A - nums[i])) {
            icanA[i] = true;
        }
    }
    
}