#include <bits/stdc++.h>

using namespace std;

#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

void solve() {
    int N, Q; cin >> N >> Q;
    vt<int> B(N);
    vt<int> c(N); //
    rep(i, 0, N) {
        cin >> B[i];
    }
    vt<ii<3>> qs(Q);
    vt<vt<int>> minima(N);
    rep(i, 0, N) {
        minima[i].add(i);
    }
    rep(i, 0, Q) {
        int x, y, z; cin >> x >> y >> z; x--; y--; z--;
        qs[i] = { x, y, z };
    }

    bool ok = true;
    
    while (Q --> 0) {
        auto [u, v, w] = qs[Q];
        //"unknown" is the same as known basically
        
        c[w] = 1;
    }
    if (!ok) {
        cout << -1 << "\n";
        return;
    }
    rep(i, 0, N) {
        cout << c[i] << " ";
    }
    cout << "\n";
    /*

    going in reverse
    we figure out our last modification, and then see how we're used.
    for modification Q - 1, we know x, y are from the array
    okay, but we know nothing about z as we continue going backwards in time.
    but we can come up with a valid array (set z to 1e9)
    so we will have "unknown" values (>= 0)
    but suppose we have a modification with a known and unknown value
    if known != result, then unknown was actually result.
    otherwise, unknown >= known (update constraint)
    
    unknown and unknown!
    ONE of the two is = result; the other is >= result.
    but ONE must be equal to result. so actually we have to store this pair
    and if we ever update one > result, then the other is forced to be strict. simple.
    

    */
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T --> 0) { solve(); }
}