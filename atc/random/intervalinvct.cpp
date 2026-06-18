#include <bits/stdc++.h>

using namespace std;
#define int long long
const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

namespace seg {

int query(int l, int r, vt<int> &t) {
    int res = 0;
    for (l += size(t) >> 1, r += size(t) >> 1; l < r; l /= 2, r /= 2) {
        res += (l & 1 ? t[l++] : 0) + (r & 1 ? t[--r] : 0);
    }
    return res;
}
void update(int i, int v, vt<int> &t) {
    for (t[i += size(t) >> 1] = v; i > 1; i >>= 1) t[i>>1] = t[i] + t[i^1];
}

}; //namespace seg

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    int K; cin >> K;
    vt<int> P(N);
    for (int i = 0; i < N; i++) cin >> P[i], P[i]--;
    int cur = 0;
    int j = 0;
    int64_t ans = 0;
    vt<int> occ(2 * N);
    set<int> pref_good;

    for (int i = 0; i < N; i++) {
        //insert i
        cur += seg::query(P[i], N, occ);
        seg::update(P[i], occ[P[i] + N] + 1, occ);
        //do insertion stuff
        auto it = pref_good.upper_bound(P[i]);
        if (it != pref_good.end()) { //remove these
            while (it != pref_good.end()) {
                it = pref_good.erase(it);
            }
        }   else if (i > 0 && pref_good.count(P[i-1]) || i == 0) {
            pref_good.insert(P[i]);
        }
        
        bool del = false;
        while (cur > K) {
            del = true;
            seg::update(P[j], occ[P[j] + N] - 1, occ);
            cur -= seg::query(0, P[j], occ);
            if (pref_good.count(P[j])) {
                pref_good.erase(P[j]);
            }
            j++;
        }
        if (del) for (int k = j; k < i; k++) {
            if (seg::query(0, P[k], occ) == k - j) {
                pref_good.insert(P[k]);
            }   else {
                break;
            }
        }
        
        if (cur == K) {
            if (K == 0) {
                ans += pref_good.size();
            }   else
            ans += 1 + pref_good.size();
        }
    }
    cout << ans << endl;
}
/*
sliding window?
to summarize: use a segment tree to maintain inversions.

what can we use to maintain prefix?
specifically: on add, remove elements in the prefix > itself. (deque ?)
if the element before us is in good or we're first, put into prefix.
to delete:
*/