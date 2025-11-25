#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T, int D> struct mt : public vt<mt<T, D - 1>> {
    template<class...A> mt(int n = 0, A... r) : vt<mt<T, D - 1>>(n, mt<T, D - 1>(r...)) {} };
template<class T> struct mt<T, 1> : public vt<T> {
    mt(int n = 0, const T &def = T()) : vt<T>(n, def) {} };

vector<int> sieve;
mt<int, 2> pfs;

void era(int n) {
    sieve.resize(n + 1);
    pfs.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) { continue; }
        for (int j = i; j <= n; j += i) {
            pfs[j].add(i);
            sieve[j] = i;
        }
    }
}

void solve() {
    int N; cin >> N;
    vt<int> A(N);
    map<int, int> cnt;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        for (int x : pfs[A[i]]) {
            cnt[x]++;
        }
    }
    vt<int> B(N);
    int min1 = MOD, min2 = MOD;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        if (B[i] < min1) { min2 = min1; min1 = B[i]; }
        else if (B[i] < min2) { min2 = B[i]; }
    }

    for (auto [v, f] : cnt) {
        if (f > 1) {
            cout << 0 << "\n";
            return;
        }
    }

    int ans = min1 + min2;

    vt<int> minis;
    for (int i = 0; i < N; i++) {
        if (B[i] == min1) {
            minis.add(i);
        }
        for (int x : pfs[A[i] + 1]) {
            if (cnt[x]) {
                ans = min(ans, B[i]);
            }
        }
    }
    if (size(minis) == 1) {
        int mini = ranges::find(B, min1) - begin(B);
        int val = A[mini];
        for (auto [v, f] : cnt) {
            if (!f) { continue; }
            if (ranges::find(pfs[val], v) != pfs[val].end()) { continue; }
            int ceil_q = (val + v - 1) / v;
            int need = ceil_q * v - val;
            ans = min((long) need * min1, (long) ans);
        }
    }   else {
        for (int mini : minis) {
            int val = A[mini] + 1;
            for (int x : pfs[val]) {
                if (cnt[x]) {
                    cout << min1 << "\n";
                    return;
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    era(200000);
    int T; cin >> T; while (T--) { solve(); }
}