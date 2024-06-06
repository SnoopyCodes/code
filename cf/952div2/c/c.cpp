#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve() {
    int N; cin >> N;
    //wait what is this
    vector<int> multiply(N);
    int mn = INT_MAX;
    for (int i = 0; i < N; i++) {
        cin >> multiply[i];
        mn = min(mn, multiply[i]);
    }
    vector<int> ans(N);
    //now what
    //so they are individual?
    //i think we just bsearch
    //not bsearch we cant bsearch on anything
    //if we say we have a 
    //is this some weird ternary search thing
    //okay so it must satisfy like
    //each of multiply * x > total
    //x1 + ... xn = total
    //this should help
    //it doesnt make sense to randomly guess high
    //does it?
    //i think it is optimal to guess high actually
    //what should we guess at for each one?
    //1e9 * n
    ll target = 1e9 * mn - 1;  //this is max amount
    for (int i = 0; i < N; i++) {
        ans[i] = (target / multiply[i]) + 1;
    }
    ll total = 0;
    for (int i = 0; i < N; i++) {
        total += ans[i];
    }
    if (total > target) {
        cout << -1 << "\n"; return;
    }
    for (int i = 0; i < N; i++) {
        assert((ll) ans[i] * multiply[i] > target);
        cout << ans[i];
        if (i != N - 1) { cout << " "; }
    }
    cout << "\n";

}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while(T){T--;solve(); }
}