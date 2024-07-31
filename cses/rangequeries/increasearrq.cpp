#include <bits/stdc++.h>

using namespace std;
using ll = long long;
vector<ll> seg;
int N;
ll query(int l, int r) {
    ll ans = 0;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { ans += seg[l++]; }
        if (r & 1) { ans += seg[--r]; }
    }
    return ans;
}
void alter(int p, ll val) {
    seg[p + N] = val;
    for (p = (p + N) / 2; p > 0; p /= 2) {
        seg[p] = seg[2 * p] + seg[2 * p + 1];
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    //literally kill me
    //non binlift sol!!!!
    //just move the fking binlift module into gold atp
    //why does nextlarger have to be ll? idk!

    int Q; cin >> N >> Q;
    vector<int> vals(N);
    vector<ll> nextlarger(N);
    vector<ll> ranges(N);
    vector<ll> pfx(N+1);
    vector<vector<array<int, 2>>> queries(N);
    seg.resize(2 * N);
    vector<ll> answers(Q);

    for (int i = 0; i < N; i++) {
        cin >> vals[i];
        pfx[i+1] = pfx[i] + vals[i];
    }

    //implicit stack, thanks @iframe
    nextlarger[N - 1] = N;
    for (int i = N - 2; i > -1; i--) {
        if (vals[i] < vals[i+1]) {
            nextlarger[i] = i + 1;
        }   else {
            int large = nextlarger[i+1];
            while (large != N && vals[large] <= vals[i]) { large = nextlarger[large]; }
            nextlarger[i] = large;
        }
        ranges[i] = (nextlarger[i] - (i + 1)) * vals[i] - (pfx[nextlarger[i]] - pfx[i+1]);
    }
    
    map<int, int> active;
    for (int i = 0; i < N; i = nextlarger[i]) {
        seg[i + N] = ranges[i];
        active[i] = nextlarger[i];
    }
    for (int i = N - 1; i > 0; i--) {
        seg[i] = seg[2 * i] + seg[2 * i + 1];
    }

    for (int i = 0; i < Q; i++) {
        int a, b; cin >> a >> b; a--;
        queries[a].push_back({b, i});
    }
    
    for (int i = 0; i < N; i++) {  //answer queries
        for (auto const& [r, j] : queries[i]) {
            answers[j] = query(0, r);
            //this sums all segments, but if the last segments goes past we haven't accounted for
            auto const&[s, e] = *--active.upper_bound(r);
            if (s >= r) { continue; }  //why is this an edge case
            answers[j] -= ll(vals[s]) * (e - r) - (pfx[e] - pfx[r]);
        }
        //remove segment i
        alter(i, 0);
        active.erase(i);
        //activate others
        for (int j = i + 1; j < nextlarger[i]; j = nextlarger[j]) {
            alter(j, ranges[j]);
            active[j] = nextlarger[j];
        }
    }

    for (int i = 0; i < Q; i++) {
        cout << answers[i] << "\n";
    }

}