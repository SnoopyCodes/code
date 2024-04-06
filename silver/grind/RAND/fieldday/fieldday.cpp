#include <bits/stdc++.h>

using namespace std;
vector<int> teams;
vector<int> sob;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int C, N; cin >> C >> N;
    teams.resize(N);
    sob.resize(1 << C, 18);
    //put everything into an integer
    //we can iterate over all possibilities
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < C; j++) {
            int g = (s[j] == 'G');
            teams[i] |= (g << j);
        }
        sob[teams[i]] = 0;
    }
    for (int i = 0; i < 1 << C; i++) {
        for (int j = 0; j < C; j++) {
            sob[i ^ (1 << j)] = min(sob[i]+1, sob[i ^ (1 << j)]);
        }
    }
    for (int i = 0; i < N; i++) {
        int x = 0;
        for (int j = 0; j < C; j++) {
            x |= teams[i] ^ (1 << j);
        }
        cout << C - sob[teams[i] ^ ((1 << C) - 1)] << "\n";
    }
}