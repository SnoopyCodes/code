#include <bits/stdc++.h>

using namespace std;
void solve() {
    string beg; cin >> beg;
    string res; cin >> res;
    //if one letter is mapped to multiple then its joever
    int N = beg.size();
    vector<int> to(52, -1);
    for (int i = 0; i < N; i++) {  //find hte mapping
        int idx;
        if (beg[i] >= 'a') { idx = beg[i] - 'a'; }
        else { idx = beg[i] - 'A' + 26; }

        int ridx;
        if (res[i] >= 'a') { ridx = res[i] - 'a'; }
        else { ridx = res[i] - 'A' + 26; }

        if (to[idx] == -1) { to[idx] = ridx; }
        else if (to[idx] != ridx) { cout << -1 << "\n"; return; }
    }
    bool doesswap = false;
    vector<bool> visited(52);
    for (int i = 0; i < 52; i++) {
        if (to[i] == -1) { continue; }
        visited[to[i]] = true;
        if (to[i] != i) { doesswap = true; }
    }
    int cnt = 0;
    for (int i = 0; i < 52; i++) { cnt += visited[i]; visited[i] = false; }
    if (doesswap && cnt == 52) { cout << -1 << "\n"; return; }
    vector<int> subtract(52);
    vector<int> in_cycle(52, -1);
    int cyc = 0;
    //okay and now the answer is size of all cycles + 1?
    //not quite..
    //ok i think the problem rn is that
    //we keep adding that one extra for "in a cycle"
    int ans = 0;
    //functional graph
    for (int i = 0; i < 52; i++) {
        if (visited[i]) { continue; }
        if (to[i] == i) { continue; }
        if (to[i] == -1) { continue; }
        int cur = i;
        vector<bool> on_stack(52);
        while (to[cur] != -1 && cur != to[cur] && !visited[cur]) {
            ans++;
            on_stack[cur] = true;
            visited[cur] = true;
            cur = to[cur];
        }

        if (on_stack[cur]) {
            int orig = cur;
            cur = to[cur];
            in_cycle[orig] = cyc;

            while (cur != orig) {
                in_cycle[cur] = cyc;
                cur = to[cur];
            }
            if (in_cycle[i] == -1) { ans--; subtract[cyc] = true; }
            ans++;
            cyc++;

        }   else if (to[cur] != -1 && cur != to[cur]) {  //hit a cycle
            if (in_cycle[cur] != -1 && !subtract[in_cycle[cur]]) { ans--; subtract[in_cycle[cur]] = true; }
        }
    }
    cout << ans << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}