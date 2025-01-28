#include <bits/stdc++.h>
#define long int64_t
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N), B(N), sorted(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sorted[i] = A[i];
    }
    long current = 0;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        current += abs(A[i] - B[i]);
    }
    //-1, 0, 4
    //ignore modulus for now
    //we can sort, find delta, binary search for best element
    //suppose that we are erasing some element
    //what do we want to find
    //element as close to B[i] as possible
    sort(sorted.begin(), sorted.end());
    int best = 0;
    for (int i = 0; i < N; i++) {
        int ind = upper_bound(sorted.begin(), sorted.end(), B[i]) - sorted.begin();
        int diff = abs(A[i] - B[i]);
        if (ind > 0) { best = max(best, diff - (B[i] - sorted[ind-1])); }
        if (ind < N - 1) { best = max(best, diff - (sorted[ind] - B[i])); }
    }
    cout << (current - best) % MOD << "\n";
}