#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> farms;
vector<int> infected;
int dfs(int barn) {
    int steps = 0;
    int cows = 1;
    int infect = 0;
    for (int i : farms[barn]) {
        if (infected[i] == 0) {
            steps++;
            infect++;
            infected[i]++;
            steps += dfs(i);
        }
    }
    while (cows <= infect) { cows *= 2; steps++; }
    return steps;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    farms.resize(N);
    infected.resize(N);
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        farms[a].push_back(b);
        farms[b].push_back(a);
    }
    infected[0]++;
    cout << dfs(0);
    //try simple first- find the number of connections to the barn in question, how many need to be infected, and then double up to >infect
    //send them over and repeat
}