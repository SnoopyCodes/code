#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize

using namespace std;

void solve() {
    int N; cin >> N;
    vec<bool> visit(N);
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        visit[i] = c == '1';
    }
    //min money to spend
    //he can always buy, good
    //thus, the goal is to maximize the amount of times we can capitalize on the pay off
    //this seems dp ish
    //we have a couple options
    //if there is a day we buy, do we buy it all?
    //suppose we don't, to save some for later
    //11111
    //day 1 nothing day 2 nothing day 3 buy cost 3 day 
    //choose some days with visit[i] = 1
    //choose all the days at the end, so we skip the most
    //would be optimal if some things were not turned off
    //uhh ok
    //for the ones that are off
    reverse(visit.begin(), visit.end());
    long ans = (long) N * (N + 1) / 2;
    set<int> off, on;
    for (int i = 0; i < N; i++) {
        if (visit[i]) {on.insert(-i); }
        else { off.insert(i); }
    }
    for (int i = 0; i < N; i++) {
        if (visit[i]) { on.erase(-i); }
        else { off.erase(i); }
        if (!visit[i]) { continue; }
        //select a day to sacrifice
        //days that we cannot visit
        if (off.empty() && on.empty()) { break; }
        if (!off.empty()) {
            off.erase(off.begin());
        }   else {
            int j = *on.begin(); on.erase(on.begin());
            visit[-j] = false;
        }
        ans -= N - i;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}