#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> coins;
vector<vector<int>> rooms;
vector<ll> ans; //contains the max if you start at index i

vector<bool> on_stack;
vector<int> found_cycle;
bool on_cycle;
int end_cycle;
ll dfs(int v) {
    if (on_stack[v]) {
        on_cycle = true;
        end_cycle = v;
        return 0;
    }
    if (ans[v]) { return ans[v]; }
    on_stack[v] = true;
    bool part = false;
    for (int close : rooms[v]) {
        ll prev = ans[v];
        ans[v] = max(ans[v], dfs(close));
        //it does not propagate to the other dfs's
        //okay good
        if (on_cycle) { ans[v] = prev; part = true; on_cycle = false; }
    }
    //okay so if we have found a cycle
    //we should be part of it
    ans[v] += coins[v];
    //is adding coins here right?
    if (part) {
        if (end_cycle == v) {
            on_cycle = false;
            ll cycle_plus = coins[v];
            for (int in_cycle : found_cycle) {
                cycle_plus += coins[in_cycle];
            }
            // now we need to consider the best branch away from cycle
            // right now, all ans[i] for i in cycle are best branch from that one
            // plus coins[i]
            ll best_away = 0;
            for (int in_cycle : found_cycle) {
                best_away = max(best_away, ans[in_cycle] - coins[in_cycle]);
            }
            ans[v] = cycle_plus + best_away;
            for (int in_cycle : found_cycle) {
                ans[in_cycle] = ans[v];
                
            }
        }   else {
            on_cycle = true;
            found_cycle.push_back(v);
        }
    }
    on_stack[v] = false;
    return ans[v];
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    coins.resize(N);
    rooms.resize(N);
    ans.resize(N);
    on_stack.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        rooms[a].push_back(b);
    }
    ll best = 0;
    for (int i = 0; i < N; i++) {
        if (!ans[i]) {
            best = max(best, dfs(i));
        }
    }
    cout << best << "\n";
}