#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
ll exp(ll x, ll p, ll m) {
    ll res = 1;
    while (p > 0) {
        if (p % 2 == 1) { res = res * x % m; }
        x = x * x % m;
        p /= 2;
    }
    return res;
}

void solve() {
    int N; cin >> N;
    //only 10 bits..
    //find for each one the probability of having it on and off
    //then brute force :holyf:
    //yeah if i could get around the multiplication i would win this
    vector<int> A(N);
    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    //pls im literally retarded
    vector<array<int, 2>> probs(10);
    for (int i = 0; i < 10; i++) {
        int p = 1, q = 1; //p/q chance of having 0
        for (int j = 0; j < N; j++) {
            if (A[i] & 1 << j) {
                
            }
        }
    }
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}