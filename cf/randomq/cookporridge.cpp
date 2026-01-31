#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

struct solve {

solve() {
    int N, D; cin >> N >> D;
    vt<int> k(N), s(N);
    for (int i = 0; i < N; i++) {
        cin >> k[i] >> s[i];
    }
    if (D < N) {
        cout << -1 << "\n";
        return;
    }
    vt upd(D, deque<int>());
    vt ins_after(N, vt<int>());
    deque<int> order;
    set<int> fed;
    /*
    oh just always make it an increasing sequence
    why is this acutally a decent problem?
    no wonder its got <100 solves by < 1600s xd
    */
    int ans = -1;
    order.add(0);
    for (int i = 1; i < N; i++) ins_after[0].add(i);
    for (int t = 0; t < D; t++) {
        //they return by s
        assert(!order.empty());
        bool sorted = true;
        for (int i = 0; i + 1 < size(order); i++) {
            if (k[order[i]] > k[order[i + 1]]) {
                sorted = false;
            }
        }
        if (!sorted) {
            for (int x : order) {
                cout << x << " ";
            }
            cout << endl;
        }
        assert(sorted);
        int u = order.front();
        cout << "time " << t + 1 << ": feeding " << u << endl;
        fed.insert(u);
        if (fed.size() == N) {
            ans = t + 1;
            break;
        }
        order.pop_front();
        // if (!ins_after[u].empty()) {
        //     int maxk = -1;
        //     vt<int> ins_ord;
        //     for (int v : ins_after[u]) {
        //         cout << "inserting " << v;
        //         if (maxk == -1 || k[v] > k[maxk]) {
        //             maxk = v;
        //             ins_ord.add(v);
        //             cout << " new spot";
        //         }   else {
        //             ins_after[maxk].add(v);
        //             cout << " in " << maxk;
        //         }
        //         cout << "\n";
        //     }
        //     for (int i = ssize(ins_ord) - 1; i > -1; i--) {
        //         order.push_front(ins_ord[i]);
        //     }
        //     ins_after[u].clear();
        // }
        
        if (t + s[u] < D) { upd[t + s[u]].add(u); }
        ranges::sort(upd[t], [&](int i, int j) { return s[i] < s[j]; });
        ranges::reverse(ins_after[u]);
        for (int v : ins_after[u]) {
            upd[t].push_front(v);
        }
        ins_after[u].clear();
        for (int u : upd[t]) {
            // cout << "update: " << u << endl;
            //assertion: order is in increasing order of k
            //find minimum i : k[i] >= k[u]
            if (order.empty() || k[order.back()] < k[u]) {
                cout << "fronting " << u << endl;
                order.push_front(u);
                continue;
            }
            int lo = -1, hi = ssize(order) - 1;
            while (lo + 1 < hi) {
                int m = (lo + hi) / 2;
                if (k[order[m]] >= u) { hi = m; }
                else { lo = m; }
            }
            // cout << "inserting after " << order[hi] << endl;
            ins_after[order[hi]].add(u);
        }
        
    }
    cout << ans << "\n";
}

};

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}