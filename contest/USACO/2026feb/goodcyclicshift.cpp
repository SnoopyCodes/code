#include <bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i,a,b) for (auto i=a; i<(b); i++)
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

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
void update(int p, int val) {
    seg[p += N] = val;
    while (p >>= 1) { seg[p] = seg[2 * p] + seg[2 * p + 1]; }
}


void solve() {
    cin >> N;
    seg = vt<int> (2 * N);
    vt<int> P(N), inv(N);

    rep(i, 0, N) cin >> P[i], P[i]--, inv[P[i]] = i;
    
    vt<int> inversions(N);
    rep(i, 0, N) {
        inversions[0] += query(P[i], N);
        update(P[i], 1);
    }
    rep(i, 0, N - 1) {
        //we will now move P[j = N - i - 1] to the beginning of the array.
        //there are P[j] elements < P[j]
        int &u = inversions[i + 1];
        u += inversions[i];
        u += P[i];
        u -= N - P[i] - 1;
    }
    vt<int> df(N + 2);
    int init = 0;
    rep(i, 0, N) {
        init += abs(P[i] - i);
    }
    rep(i, 0, N) {
        int &u = P[i];
        //u starts at index i.
        if (u <= i) {
            //decreasing slope from i to u
            //then increasing from i to 0
            //from [1, until we reach u] it is slope of -1
            //then [when we reach u, until we reach 0] it is slope of 1
            //then [when we are N - 1, u] it is -1 again
            int t = i - u;
            df[1] -= 1;
            df[t + 1] += 1;
            int tt = i;
            df[t + 1] += 1;
            df[tt + 1] -= 1;
            //big jump at [tt, tt + 1]: we are contributing u, now we are contributing N - u - 1
            df[tt + 1] -= u;
            df[tt + 2] += u;
            df[tt + 1] += N - u - 1;
            df[tt + 2] -= N - u - 1;
            
            //[N - 1, u] it is -1
            df[tt + 1] += -1;
            df[N] += 1;
        }   else {
            //increasing from i to 0
            //decreasing from N - 1 to u
            //increasing from u to i
            int t = i;
            df[1] += 1;
            df[t + 1] -= 1;
            df[t + 1] -= u;
            df[t + 1] += N - u - 1;
            df[t + 2] += u;
            df[t + 2] -= N - u - 1;
            //we are at time i + 1
            //now we switch to negative until we hit next
            df[t + 1] -= 1;
            int tt = N - u - 1 + i + 1;
            df[tt + 1] += 1;
            df[tt + 1] += 1;
            df[N] -= 1;
        }
    }
    vt<int> ans;
    int delta = 0;
    rep(i, 0, N) {
        delta += df[i];
        init += delta;
        if (init / 2.0 >= inversions[i]) {
            ans.add(i);
        }
    }
    reverse(begin(ans), end(ans));
    cout << size(ans) << "\n";
    for (int i = 0; i < size(ans); i++) {
        if (i) cout << " ";
        cout << N - ans[i] - 1;
    }
    cout << "\n";
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}