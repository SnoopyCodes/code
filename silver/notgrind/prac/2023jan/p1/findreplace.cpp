#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<int> swaps(52);  //0-25 = a-z, 26-51 = A-Z
vector<bool> visited(52);
vector<bool> cycled(52);
bool dfs(int i) {
    if (visited[i]) { cycled[i] = true; return true; }  //it is a cycle bc we visited this before 
    visited[i] = true;
    if (swaps[i] == -1) { return false; }  //not a cycle
    if (swaps[i] == i) { return false; } //not a cycle
    int ans = dfs(swaps[i]);
    if (ans) { cycled[i] = true; }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 52; i++) {
            swaps[i] = -1;
        }
        string cur, targ;
        cin >> cur >> targ;
        bool possible = true;
        for (int i = 0; i < cur.size(); i++) {
            int curi, targi;
            if (cur[i] >= 97) {
                curi = cur[i] - 'a';
            }   else {
                curi = cur[i] - 'A' + 26;
            }
            if (targ[i] >= 97) {
                targi = targ[i] - 'a';
            }   else {
                targi = targ[i] - 'A' + 26;
            }
            if (swaps[curi] != -1 && swaps[curi] != targi) {
                possible = false; break;
            }   else {
                swaps[curi] = targi;
            }
        }
        if (!possible) { cout << -1 << "\n"; continue; }
        //consider cases for which it is impossible.
        //if a certain char has to transmute into 2 different ones, then it is impossible i think
        //yes, it is absolutely impossible
        //the ordering doesn't really matter does it?
        //we can make a "graph" almost of trying to map stuff to stuff
        //okay so there are two ways this can happen
        //there are no cycles- instantly ok
        //if there are cycles
        //if there is one open spot then we are ok if not we are screwed
        //abc
        //bac
        //a -> d  dbcd
        //b -> a  dacd
        //c -> b  dabd
        //d -> b  cabc
        //we can combine the ones that are going to the same one
        //we need only do this once, though
        //okay so it doesn't work for cases where the target has all 52
        //otherwise it works
        vector<bool> has(52);
        for (int i = 0; i < 52; i++) {
            if (swaps[i] == -1) { continue; }
            has[swaps[i]] = true;
        }
        bool hasall = true;
        for (int i = 0; i < 52; i++) {
            if (!has[i]) { hasall = false; break; }
        }
        if (hasall && cur != targ) { cout << -1 << "\n"; continue; }
        else if (cur == targ) { cout << 0 << "\n"; continue; }
        //now for cycles
        //answer is number of connections + number of cycles
        int count = 0;
        for (int i = 0; i < 52; i++) {
            if (swaps[i] != -1 && swaps[i] != i) { count++; }
            if (swaps[i] == i || swaps[i] == -1 || cycled[i]) { continue; }
            visited.resize(52);
            count += dfs(i);
        }
        cout << count << "\n";
    }
}