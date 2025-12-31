#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

#define rep(i, a, b) for (auto i=a; i<(b); i++)

void solve() {
    int N, M; cin >> N >> M;
    vt<ii<2>> A(N);
    rep(i, 0, N) {
        cin >> A[i][0];
        A[i][1] = i;
    }
    if (M > N / 2) {
        cout << -1 << "\n";
        return;
    }

    ranges::sort(A);
    int ct = 0;
    vt<ii<2>> ops;
    
    if (M == 0) {
        long sum = 0;
        rep(i, 0, N - 1) {
            sum += A[i][0];
        }
        if (sum < A[N - 1][0]) {
            cout << -1 << "\n";
            return;
        }
        //now what?
        //we have to find an even/odd length sequence that is > this guy
        //wait we dont but save that problem for later
        //choose the last some numbers to go with N - 1
        //then just eliminate until those remain
        ranges::reverse(A);
        while (sum - A.back()[0] >= A[0][0]) {
            ct++;
            sum -= A.back()[0];
            int u = A.back()[1];
            A.pop_back();
            int v = A.back()[1];
            ops.add({ u, v });
        }
        while (size(A) > 1) {
            ct++;
            int u = A.back()[1];
            A.pop_back();
            ops.add({ u, A[0][1] });
        }
        cout << ct << "\n";
        rep(i, 0, ct) {
            cout << ops[i][0] + 1 << " " << ops[i][1] + 1 << "\n";
        }
        return;
    }

    ranges::reverse(A);
    while (size(A) > 2 * M) {
        ct++;
        int u = A.back()[1];
        A.pop_back();
        int v = A.back()[1];
        ops.add({ u, v });
    }
    rep(i, 0, size(A) / 2) {
        int u = A[i][1];
        int v = A[size(A) - i - 1][1];
        ct++;
        ops.add({ u, v });
    }

    cout << ct << "\n";
    rep(i, 0, ct) {
        cout << ops[i][0] + 1 << " " << ops[i][1] + 1 << "\n";
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) solve();
}