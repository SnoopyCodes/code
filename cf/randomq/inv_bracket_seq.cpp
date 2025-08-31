#include <bits/stdc++.h>

using namespace std;
#define EN(i, v) " \n"[i == v.size() - 1]
#define long long long
const int  BIG = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array< int, z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

void solve() {
    string ss; cin >> ss;
    int N = size(ss);
    vt<int> s(N);
    for (int i = 0; i < N; i++) {
        char c = ss[i];
        s[i] = c == '(' ? 1 : -1;
    }
    vt<int> pf(N), sf(N);
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += s[i];
        pf[i] = sum;
    }
    sum = 0;
    for (int i = N - 1; i >= 0; i--) {
        sum += s[i];
        sf[i] = sum;
    }
    // for each index i, find the number of prefix that match its suffix
    long ans = 0;
    vt<int> cnt_pf(N + 1);
    for (int i = 0; i < N; i++) {
        cout << cnt_pf[i] << EN(i, cnt_pf);
    }
    for (int i = 0; i < N; i++) {
        cout << i;
        if (s[i] <= 0) {
            ans += cnt_pf[-s[i]];
            cout << " " << cnt_pf[-s[i]];
        }
        cout << "\n";
        cnt_pf[pf[i]]++;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}