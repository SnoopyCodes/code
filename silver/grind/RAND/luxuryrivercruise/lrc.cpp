#include <bits/stdc++.h>

using namespace std;
const int l = 'L';
const int r = 'R';
vector<pair<int, int>> ports;
vector<int> dirs;
//https://usaco.org/index.php?page=viewproblem2&cpid=284
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("cruise.in", "r", stdin);
    freopen("cruise.out", "w", stdout);
    int N, M, K; cin >> N >> M >> K;
    ports.resize(N);
    dirs.resize(M);
    //okay so it has 2 choices
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        ports[i] = {a, b};
    }
    for (int i = 0; i < M; i++) {
        char c;
        cin >> c;
        dirs[i] = c;
    }
    //how do cycles work?
    //if reached 1 when instruction 0 is to be executed then we have a cycle
    //alternatively
    //if we reach the same port at an instruction we've reached before we have a cycle
    //we can just run all the way down a thing and then we're good to go 
    //i think we're guaranteed to get a cycle
    //just store all occurrences in a huge matrix
    //then we can take the number of cycles to do
    vector<vector<int>> occs(N, vector<int>(M, -1));  //store for port i whether we visited on instruction j if -1 we never visited before
    int instruct = 0, cur = 0, iter = 0;
    while (iter < K && occs[cur][instruct] == -1) {
        occs[cur][instruct] = iter;
        //still have to execute instruction
        cur = dirs[instruct] == l ? ports[cur].first : ports[cur].second;  //l or r
        instruct++;
        if (instruct == M) { instruct = 0, iter++; }
    }
    if (iter == K) {
        cout << cur+1 << "\n";
        return 0;
    }
    int cycle = iter - occs[cur][instruct];
    //we want to go to K-1
    int rem = (K-1-iter) % cycle;
    //so now we need to play out M rem times
    //and then finish it
    for (int i = 0; i <= rem; i++) {
        while (instruct < M) {
            cur = dirs[instruct] == l ? ports[cur].first : ports[cur].second;
            instruct++;
        }
        instruct = 0;
    }
    cout << cur+1;
}