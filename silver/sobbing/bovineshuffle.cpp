#include <bits/stdc++.h>

using namespace std;
vector<int> cows;
vector<int> visited;
vector<int> on_stack;
void dfs(int i) {
    
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    cows.resize(N);
    //the problem boils down to finding the number of vertices that are in a cycle
    //uhh
    //just find a cycle i think
    for (int i = 0; i < N; i++) {
        cin >> cows[i]; cows[i]--;
    }

}