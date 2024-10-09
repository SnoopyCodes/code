#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v;
void solve() {
    int N; cin >> N;
    v.clear();
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    //so we need to determine hbow many times to do it
    //find the diff between adj
    //then add the 
    int mx = 0;
    ll sum = 0;
    for (int i = 1; i < N; i++) {
        int diff = max(0, v[i-1] - v[i]);
        if (diff != 0) {
            v[i] = v[i-1];
            mx = max(mx, diff);
            sum += diff;
        }
    }
    cout << mx + sum << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T) { T--; solve(); }
}