#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> seg;
int N, X;
vector<int> v;
void init() {
    seg.resize(2 * X);
}
void modify(int p) {
    seg[p + X]++;
    for (p = (p + X) / 2; p > 0; p /= 2) {
        seg[p] = seg[p * 2] + seg[p * 2 + 1];
    }
}
ll query(int l, int r) {
    if (l == X) { return 0; }
    ll ans = 0;
    for (l += X, r += X; l < r; l /= 2, r /= 2) {
        if (l & 1) { ans += seg[l++]; }
        if (r & 1) { ans += seg[--r]; }
    }
    return ans;
}
void solve() {
    cin >> N >> X;
    X++;
    v.resize(N);
    seg.clear();
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        //we don't eat a multiple of it
        //and we need to track the ones that will stop it from overflowing
        //this is so stupid
    }
    init();
    ll sum = 0;
    ll bad = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i];
        ll dont = 0;
        if (v[i] > X) { bad += i + 1; modify(0); continue; }
        //
        dont += query(0, X - v[i]);
        cout << "final:" << dont << "\n";
        bad += dont;
        modify(sum % X);
        cout << "\n";
        //restart
        //the process is:
        //find the number of numbers below us so that
        //sum -theirsum % X != 0
        //and v[i] + theirsum % X <= X 
        //we can complementary count
        //so we can query for 
        //sum % X
        //and we can query for
        //X - v[i]
    }
    cout << bad << "\n";
    cout << N * (N + 1) / 2 - bad << "\n";
}//??
//so (1, 1), (2, 2)
//wait it actually just becomes 0
//so on the last op it cant overflow
//how do we track that
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}