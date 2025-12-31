#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

#define rep(i,a,b) for(int i=a; i <(b); i++)

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

bool ok(int amt, int K) {
    return amt >= K + (N - amt);
}

void solve() {
    int K; cin >> N >> K;
    seg.resize(2 * N);
    using vi = vt<int>;
    vi freq(N);
    vi A(N); rep(i,0,N) cin >> A[i], A[i]--, freq[A[i]]++;
    rep(i,0,N) alter(i, freq[i]);
    /*
    for given x, y we can evaluate in O(N)
    the prefix sum array must be >= k at the end?
    so the problem boils down to the number of elements in a range
    */
    
    int ai = -1, aj = -1; { //initialize these
        int j = 0;
        int ans = MOD;
        rep(i,0,N) {
            while (j < N && !ok(query(i, j), K)) { j++; }
            if (ok(query(i, j), K) && j - i < ans) {
                ans = j - i;
                ai = i, aj = j - 1;
            }
        }
    }

    cout << ai + 1 << " " << aj + 1 << "\n";
    int k = 0;
    int i = 0, j = 0;
    int cur = 0;
    while (k < K - 1) {
        while (j < N && cur < k + 1) {
            if (ai <= A[j] && A[j] <= aj) {
                cur++;
            }   else {
                cur--;
            }
            j++;
        }
        cout << i + 1 << " " << j << "\n";
        k++;
        i = j;
    }
    cout << i + 1 << " " << N << "\n";

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve(); 
}