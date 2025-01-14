#include <bits/stdc++.h>
#define long int64_t
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    int maxv = 0;
    int minv = 1e9;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        maxv = max(maxv, A[i]);
        minv = min(minv, A[i]);
    }
    long sum = minv;
    //for each number, see how many numbers are a multiple of it (and thus this can be gcd)
    vector<int> cnt(maxv + 1);
    vector<vector<int>> divs(maxv + 1);
    for (int i = 1; i <= maxv; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (maxv % j) { continue; }
            divs[i].push_back(j);
            if (j * j != maxv) { divs[i].push_back(maxv / j); }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int x : divs[A[i]]) {
            cnt[x]++;
        }
    }
    //welp what
    int cur = minv;
    //we need to see how to find the minimum value
    
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}