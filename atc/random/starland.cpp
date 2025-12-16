#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
#define rep(i,a , b) for (auto i = a; i < (b); i++)
#define rev(i, a, b) for (auto i = a; i > (b); i--)
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

vt<int> B;

vector<int> seg;
int N;

int query(int l, int r) {
    int res = 0;
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) { res += seg[l++]; }
        if (r & 1) { res += seg[--r]; }
    }
    return res;
}
void alter(int p, long val) {
    seg[p + N] = val;
    for (p = (p + N) / 2; p > 0; p /= 2) {
        seg[p] = seg[2 * p] + seg[2 * p + 1];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N;
    B.resize(N); rep(i, 0, N) cin >> B[i], B[i]--;
    /*
    for all subarrays find 1 + # of elements that are greater than max(B_l, B_r)
    so actually it boils down to for each element i how many left and right does it contribute
    */
    
    long ans = ((long) N * (N + 1)) / 2;

    seg.resize(2 * N);
    vt<int> bl(N), br(N);
    rep(i, 0, N) {
        bl[i] = query(0, B[i]);
        alter(B[i], 1);
    }

    seg.assign(2 * N, 0);
    rep(i, 0, N) {
        int j = N - i - 1;
        br[j] = query(0, B[j]);
        alter(B[j], 1);
    }

    
    rep(i, 0, N) {
        ans += (long) bl[i] * br[i];
    }
    cout << ans << "\n";
}