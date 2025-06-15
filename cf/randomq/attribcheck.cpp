#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;

template<class T> T mvec(T def) { return def; }
template<class T, class...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }

vector<int> seg;
int size;

int query(int p) {
    int res = 0;
    for (p += size; p > 0; p /= 2) {
        res += seg[p];
    }
    return res;
}
void upd(int l, int r) {
    for (l += size, r += size; l < r; l /= 2, r /= 2) {
        if (l & 1) { seg[l++]++; }
        if (r & 1) { seg[--r]++; }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    size = M + 1;
    //let's say we have a dp
    //calculate how many records we have currently
    //and how many go to strength
    //segtree: segtree: segtree:
    //no way.
    //it implies O(N).
    //how do we update an entire segment?
    //i feel like segtree is strong enough, no?
    //go through the list
    //ignore all the ones
    //that have abs greater than updated.
    //now put all in strength
    //can we set constraints?
    //strength: find the minimum from line it lies away.
    //uh if strength is good 
    //assume masochistic constraints and we segtree.
    //range update point query.
    
    int ups = 0;
    seg.resize(2 * (M + 1));
    for (int i = 0; i < N; i++) {
        int r; cin >> r;
        if (abs(r) > ups) { continue; }
        if (r == 0) {  //build time
            //idk how to get this fast
            vector<int> new_dp(ups + 2);
            for (int j = 0; j <= ups; j++) {
                new_dp[j] = query(j);
            }
            for (int j = ups + 1; j >= 1; j--) {
                new_dp[j] = max(new_dp[j], new_dp[j - 1]);
            }
            for (int j = 0; j < M + 1; j++) {
                seg[j] = 0;
            }
            for (int j = M + 1; j <= M + 1 + ups + 1; j++) {
                seg[j] = new_dp[j - (M + 1)];
            }
            ups++;
        }   else if (r > 0) {
            //update everything >= r
            upd(r, ups + 1);
        }   else {
            r = abs(r);
            //update 0 to ups - r + 1
            upd(0, ups - r + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i <= M; i++) {
        ans = max(ans, query(i));
    }
    cout << ans << "\n";
}