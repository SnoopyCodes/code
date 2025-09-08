#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  BIG = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

void solve() {
    int N; cin >> N;
    vt<int> A(N);
    vt<int> ct(N + 1), hit(N + 1);
    for (int &u : A) { cin >> u; ct[u]++; }

    ranges::sort(A);
    //harmonic whatever
    //but anyways
    //for a value figure out how many less than it it can use
    //2, 4, 6. 4 & 6 need to know.
    //so we can find how many it divides instead?
    //are we PIE?
    //WE ARE PIE
    long ans = N * (N - 1) / 2;
    vt<int> div_by(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            div_by[j] += ct[i];
        }
    }


    for (int i = 1; i <= N; i++) {
        if (!ct[i]) { continue; }
        for (int j = i; j <= N; j += i) {
            hit[i] += ct[j];
        }
        cout << i << " " << hit[i] << " " << ct[i] << "\n";
        if (div_by[i] % 2 == 1) { ans -= (long) hit[i] * (hit[i] - 1) / 2 * ct[i]; }
        else { ans += (long) hit[i] * (hit[i] - 1) / 2 * ct[i]; }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}