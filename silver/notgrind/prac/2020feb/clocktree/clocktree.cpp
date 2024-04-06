#include <bits/stdc++.h>

using namespace std;

vector<int> clocks;
vector<int> dummy;
vector<vector<int>> corridors;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("clocktree.in", "r", stdin);
    //freopen("clocktree.out", "w", stdout);
    int N; cin >> N;
    clocks.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> clocks[i];
        clocks[i] = 12 - clocks[i];
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        corridors[a].push_back(b);
        corridors[b].push_back(a);
    }
    //i believe there are guaranteed to be no cycles.
    //we also have O(N^2) time complexity so we can do a dfs for every single one
    //the question is, then, how do we figure out the whole tree given that we start at i?
    //there is no other path to boost i than to come straight back to it. 
    //if a non-12 room at any point has no corridors open to it such that that room's need is greater than it (and bessie is not there to boost it) then 
    //failure.
    //its always doable to turn 12 to 1 and start over.
    //im not sure if there's any benefit though... actually maybe
    //because the need of a room can be increased by 12 in this way.
    //otherwise a 12 is a roadblock
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dummy[j] = clocks[j];
            
        }
    }
}