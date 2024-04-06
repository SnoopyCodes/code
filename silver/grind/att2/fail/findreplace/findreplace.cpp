#include <bits/stdc++.h>

using namespace std;
vector<bool> used;
vector<int> target;
vector<bool> visited;
vector<bool> trial;
const int NUM = 52;
int ops = 0;
void edge(int i) {
    if (visited[i]) { return; }
    visited[i] = true;
    if (target[i] != -1) { ops++; int tmp = target[i]; target[i] = -1; edge(tmp); }
}
void cycle(int i) {  //heres a problem: for things not in a cycle we must mark it as not touched
    if (trial[i]) {
        ops++;
        for (int j = 0; j < NUM; j++) { visited[j] = visited[j] || trial[j]; }
        return;
    }
    trial[i] = true;
    if (target[i] != -1 && !visited[target[i]]) { cycle(target[i]); }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        used.clear(); used.resize(NUM);
        target.clear(); target.resize(NUM, -1);
        visited.clear(); visited.resize(NUM);
        string init; cin >> init;
        string targ; cin >> targ;
        bool valid = true;
        ops = 0;
        int total = 0;
        for (int i = 0; i < init.size(); i++) {
            int ic = init[i];
            int fc = targ[i];
            // cout << ic << " " << fc << "\n";
            if (ic < 'a') { ic -= 'A' - 26; }  //we will have uppercase 26-52
            else { ic -= 'a'; }
            if (fc < 'a') { fc -= 'A' - 26; }
            else { fc -= 'a'; }
            // cout << ic << " " << fc << "\n";
            if (target[ic] != -1 && target[ic] != fc) { valid = false; break; }  //if ic has more than 1 target
            if (target[ic] == -1) {  //set a target
                if (ic != fc)
                target[ic] = fc;
                if (!used[fc]) { total++; used[fc] = true; }
            }
        }
        if (total == NUM) {
            for (int i = 0; i < NUM; i++) {
                if (targ[i] != init[i]) { valid = false; break; }
            }
        }
        if (!valid) { cout << -1 << "\n"; continue; }
        for (int i = 0; i < NUM; i++) {
            trial.clear(); trial.resize(NUM);
            if (!visited[i])
            cycle(i);
        }
        visited.clear(); visited.resize(NUM);
        for (int i = 0; i < NUM; i++) {
            if (target[i] != -1 && !visited[i]) { ops++; }
        }
        // wait why dont we just loop through and check if its not equal
        cout << ops << "\n";
    }
}