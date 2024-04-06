#include <bits/stdc++.h>

using namespace std;
struct Cow {
    int i, cur;
    vector<int> wish;
};
int best, original;
vector<Cow> cows;
vector<int> favs;
vector<bool> visited;
void dfs(int i) {
    if (visited[i]) { return; }
    visited[i] = true;
    for (int j = 0; j < cows[original].cur; j++) {
        //check if gift i is something that they want
        bool theywantsit = false;
        //cows[orig].wish[j] is the gift (and cow) we want
        for (int k = 0; k < cows[cows[original].wish[j]].cur; k++) {
            if (cows[cows[original].wish[j]].wish[k] == i) {
                theywantsit = true; break;
            }
        }
        if (theywantsit) {
            best = min(best, j);
            dfs(j);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    favs.resize(N);
    cows.resize(N);
    for (int i = 0; i < N; i++) {
        cows[i].i = i;
        for (int j = 0; j < N; j++) {
            int want;
            cin >> want;
            want--;
            if (want == i) { cows[i].cur = j; }
            cows[i].wish.push_back(want);
        }
    }
    for (int i = 0; i < N; i++) {
        visited.clear();
        visited.resize(N);
        original = cows[i].i;
        best = cows[i].cur;
        dfs(i);
        favs[cows[i].i] = cows[i].wish[best];
    }
    for (int i = 0; i < N; i++) {
        cout << favs[i]+1 << "\n";
    }
}