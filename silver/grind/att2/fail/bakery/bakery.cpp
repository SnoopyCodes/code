#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Cow {
    ll c, m, t;
};
int N, Tc, Tm;
vector<Cow> cows;
bool valid(ll g) {  //guess
    //find the lower and upper bounds and check if they are larger or smaller
    int lx = max((ll) 1, Tc - g), hx = min(Tc + Tm - 1 - g, (ll) Tc);
    //so we check for hte minimum that lx can be
    //we must understand that if c (a) is larger then it is the limiting factor
    //so we have to check the minimum that it can be
    //on the other hand if m is larger then that is limiting
    //so check maximum (b)
    //okay i understand now
    for (int i = 0; i < N; i++) {
        if (cows[i].c == cows[i].m) {

        }
        double bound = (cows[i].c - cows[i].m * (Tc + Tm - g)) / (cows[i].c - cows[i].m);
    }
    return false;
}
void solve() {
    cin >> N >> Tc >> Tm;
    cows.clear(); cows.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].c >> cows[i].m >> cows[i].t;
    }
    int s = -1;  //dont spend any money
    int e = Tc + Tm - 2;  //max we cna spend is tc + tm - 2
    int cnt = 0;
    //find the minimum spending
    while (e > s + 1) {
        ll m = (s + e) / 2;
        if (valid(m)) {  //go lower
            e = m;
        }   else {
            s = m;
        }
    }
    cout << e << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        //:)
        solve();
    }
}