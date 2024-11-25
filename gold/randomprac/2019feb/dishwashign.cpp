#include <bits/stdc++.h>

using namespace std;

vector<int> P;

bool valid(int g) {
    set<int> active;
    for (int i = 0; i < g; i++) {
        active.insert(P[i]);
    }
    int next = *active.begin();
    deque<stack<int>> qs;
    for (int i = 0; i < g; i++) {
        //find in which stack does this belong
        //first base
        if (!qs.empty() && P[i] < qs.back().top()) {
            //find smallest larger than itself i think
            int s = -1, e = qs.size();
            while (s + 1 < e) {
                int m = (s + e) / 2;
                if (qs[m].top() <= P[i]) { s = m; }
                else { e = m; }
            }
            qs[e].push(P[i]);
        }   else {
            stack<int> st; st.push(P[i]);
            qs.push_back({st});
        }
        //try removing what we can
        while (!qs.empty() && qs.front().top() == next) {
            qs.front().pop();
            active.erase(next);
            if (!active.empty()) { next = *active.begin(); }
            if (qs.front().empty()) { qs.pop_front(); }
        }
    }
    return qs.empty();
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    int N; cin >> N;
    P.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    int s = 1, e = N + 1;
    while (s + 1 < e) {
        int m = (s + e) / 2;
        bool w = valid(m);
        if (valid(m)) { s = m; }
        else { e = m; }
    }
    cout << s << "\n";
}