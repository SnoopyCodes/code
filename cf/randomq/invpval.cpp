#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  BIG = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T, int D> struct mt : public vt<mt<T, D - 1>> {
    template<class...A> mt(int n = 0, A... r) : vt<mt<T, D - 1>>(n, mt<T, D - 1>(r...)) {} };
template<class T> struct mt<T, 1> : public vt<T> {
    mt(int n = 0, const T &def = T()) : vt<T>(n, def) {} };

void solve() {
    int N, K; cin >> N >> K;
    //N^2 ok
    //partition it into sets of k where sum of k = N and sum of C(k, 2) = C(N, 2) - K
    //eg sample is 2, 1, 1
    //oh we can N^3 DP
    vt<int> trans(N + 1);
    for (int i = 1; i <= N; i++) {
        trans[i] = i * (i - 1) / 2;
    }
    mt<ii<2>, 2> can(N + 1, trans[N] + 1, ii<2>{ -1, -1 });
    can[0][0] = { 0, 0 };
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= trans[N]; j++) {
            if (can[i][j] == ii<2>{ -1, -1 }) { continue; }
            for (int k = 1; k <= N - i && j + trans[k] <= trans[N]; k++) {
                can[i + k][j + trans[k]] = { i, j };
            }
        }
    }
    if (can[N][trans[N] - K] == ii<2>{ -1, -1 }) { cout << 0 << "\n"; return; }
    vt<int> groups;
    {
        int i = N;
        int j = trans[N] - K;
        while (i != 0 || j != 0) {
            int p = can[i][j][0];
            groups.add(i - p);
            int pj = can[i][j][1];
            i = p;
            j = pj;
        }
    }
    int pt = N;
    vt<int> ans;
    for (int x : groups) {
        for (int i = pt - x; i < pt; i++) {
            ans.add(i+1);
        }
        pt -= x;
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T --> 0) { solve(); }
}