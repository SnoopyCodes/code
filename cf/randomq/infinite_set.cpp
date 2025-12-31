#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;

#define rep(i,a,b) for (auto i=a; i<(b); i++)

set<int> kill;

struct bt {
    array<bt*, 2> c{};
    bool end = false;
    int val;
    bt(int x):val(x) {}
    void ins(int x, int b) {
        if (val == x) {
            end = true;
        }   else {
            bool is_set = x >> b & 1;

            if (!c[is_set]) {
                c[is_set] = new bt(val << 1 | is_set);
            }
            c[is_set]->ins(x, b - 1);
        }
    }

    bt *find(int x, int b) {
        if (val == x) {
            return this;
        }
        return c[x >> b & 1]->find(x, b - 1);
    }

    void search(long val) {
        if (val > 1e9) { return; }
        if (end) {
            kill.insert(val);
        }
        if (c[1]) {
            c[1]->search(val << 1 | 1);
        }
        if (c[0] && c[0]->c[0]) {
            c[0]->c[0]->search(val << 2);
        }
    }
};

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, P; cin >> N >> P;
    using vi = vt<int>;
    vi A(N);
    auto root = bt(1);
    rep(i,0,N) {
        cin >> A[i];
        root.ins(A[i], __lg(A[i]) - 1);
    }
    ranges::sort(A);
    vt<bool> marked(N);
    vi dp(P + 30);
    rep(i, 0, N) {
        if (kill.count(A[i])) { continue; }
        root.find(A[i], __lg(A[i]) - 1)->search(A[i]);
        dp[__lg(A[i])]++;
    }
    int ans = dp[0];
    rep(i, 1, P) {
        (dp[i] += dp[i - 1]) %= MOD;
        if (i > 1) {
            (dp[i] += dp[i - 2]) %= MOD;
        }
        (ans += dp[i]) %= MOD;
    }

    cout << ans << "\n";

    
    

}