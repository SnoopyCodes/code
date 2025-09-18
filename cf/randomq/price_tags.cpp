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

const int MX = 4e5 + 1;

void solve() {
    int N, Y; cin >> N >> Y;
    vt<int> ct(MX);
    while (N --> 0) {
        int x; cin >> x;
        ct[x]++;
    }
    vt<int> pf(MX + 1);
    for (int i = 1; i < MX; i++) {
        pf[i + 1] = pf[i] + ct[i];
    }

    vt<int> print(MX);
    vt<long> win(MX);
    for (int i = 1; i < MX; i++) { //the final price.
        for (int j = 2; i * j < MX; j++) { //multiplier
            int amt = pf[min(i * j + 1, MX)] - pf[(i - 1) * j + 1];
            print[j] += max(0, amt - ct[i]);
            win[j] += (long) i * amt;
        }
    }
    long ans = -INF;
    for (int i = 2; i < MX; i++) {
        ans = max(ans, win[i] - (long) Y * print[i]);
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T --> 0) { solve(); }
}