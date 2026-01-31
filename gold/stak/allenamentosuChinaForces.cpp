#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

void dnc(int l, int r, vt<int> &A, int &ans) {
    if (l + 1 == r) { return; }
    int m = (l + r) / 2;
    //make stuff on left half
    int maxv = 0, minv = MOD;
    vt<int> maxes, mins;
    for (int i = m - 1; i >= l; i--) {
        if (A[i] < minv) {
            mins.add(i);
            minv = A[i];
        }
        if (A[i] > maxv) {
            maxes.add(i);
            maxv = A[i];
        }
    }
    maxv = 0, minv = MOD;
    for (int i = m; i < r; i++) {
        maxv = max(maxv, A[i]);
        minv = min(minv, A[i]);
        int s = 0, e = size(maxes); //find first > maxv
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if (maxv >= A[maxes[m]]) {
                s = m;
            }   else {
                e = m;
            }
        }
        int lb = (maxv >= A[maxes[s]] ? maxes[s] : m);
        if (maxv >= A[maxes[s]] && s + 1 == size(maxes)) {
            lb = l;
        }
        s = -1, e = (int) size(mins) - 1; //find rightmost (in A) : theres a value <= minv
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if (A[mins[m]] > minv) {
                s = m;
            }   else {
                e = m;
            }
        }
        int rb = (A[mins[e]] <= minv) ? mins[e] : l - 2;
        if (rb < lb) { continue; }
        ans += (rb - lb + 1);
    }
    dnc(l, m, A, ans), dnc(m, r, A, ans);
}

int conta(int N, vector<int> A) {
    int ans = 0;
    dnc(0, N, A, ans);
    return ans;
}

signed main() {
    int N; cin >> N;
    vt<int> A(N); for (int &u : A) cin >> u;
    cout << conta(N, A) << "\n";
}