#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    vector<int> b(N);
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    vector<int> near_short(N, -1);
    for (int i = 1; i < N; i++) {
        int less = i - 1;
        while (h[i] <= h[less]) {
            less = near_short[less];
            if (near_short[less] == less) { less = i; break; }
        }
        near_short[i] = less;
    }
    vector<ll> dp(N);
    for (int i = 1; i < N; i++) {
        int shorter = near_short[i];
        ll best;  //query shorter, i
        //update dp[i] to be 
    }
    cout << "\n";

}