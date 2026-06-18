#include <bits/stdc++.h>

using namespace std;

#define int long long
const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    long long total = 0;

    for (int i = 0; i < N; i++) {
        int T, t, x, c; cin >> t >> T >> x >> c;
        int k = T - t;
        if (k < 1) {
            total += x * M + c;
            continue;
        }
        if (c >= k * x || M <= k) { //costs more to put in bus than it saves
            total += x * (M > k ? M : 0) + c;
            continue;
        }
        //wait we know we can fit k children into a bus without them complaining. 
        //and we stuff the remainder into one big bus.
        //so i guess for some # of buses b
        //we have bc + (M - bk >= k ? (M - bk) * x : 0)
        //we can manually cap the case and turn it into
        //bc + Mx - bkx
        //minimize b(c - kx) + Mx
        //
        //so M >= k(b + 1)
        //so b <= M / k - 1
        //thus b(c - kx) + Mx is about finding the closest multiple of (kx - c) <= Mx
        //so our desired number is Mx / (kx - c), in floor division.
        //if c >= kx just put in bus and leave.

        //ok so error here clearly
        //cap is the largest integer <= M / k - 1
        //we wnat M - b * k >= k
        //M >= k (b + 1)
        //
        int cap = (M + k - 1) / k - 1;
        int yuh = min(M * x / (k * x - c), cap);
        assert(M - yuh * k >= k);

        total += min(c * (cap + 1), c * yuh + M * x - yuh * k * x);
    }
    cout << total << endl;
}