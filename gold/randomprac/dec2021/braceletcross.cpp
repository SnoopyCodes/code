#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

void solve() {
    int N, M; cin >> N >> M;
    vt<int> state(N); //on or off
    vt<int> cur; //current sequence
    bool ok = true;
    rep(i, 0, M) {
        int K; cin >> K;
        vt<int> next(K);
        set<int> deletions, additions;
        vt<vt<int>> pos(N);
        rep(j, 0, K) {
            cin >> next[j], next[j]--, pos[next[j]].add(j);
            if (state[next[j]] == 2) {
                ok = false;
            }   else if (state[next[j]] == 0) {
                additions.insert(next[j]);
                state[next[j]] = 1;
            }
        }
        rep(j, 0, size(cur)) {
            if (find(begin(next), end(next), cur[j]) == end(next)) {
                deletions.insert(cur[j]);
                state[cur[j]] = 2;
            }
        }
        for (int x : deletions) {
            rep(z, 0, 2) cur.erase(find(begin(cur), end(cur), x));
        }
        auto test = next;
        for (int x : additions) {
            rep(z, 0, 2) test.erase(find(begin(test), end(test), x));
        }
        if (test != cur) {
            ok = false;
        }
        
        stack<int> st;
        rep(j, 0, K) {
            if (pos[next[j]][0] == j) {
                st.push(next[j]);
            }   else {
                if (st.empty() || st.top() != next[j]) {
                    ok = false;
                }
                st.pop();
            }
        }
        
        cur = next;
    }

    if (ok) {
        cout << "YES" << "\n";
    }   else {
        cout << "NO" << "\n";
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T -- > 0) solve();
}