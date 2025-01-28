#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int target; cin >> target;
    sort(A.begin(), A.end());
    //N <= 20000?
    //4e8 is slightly unbelievable to me
    //oh time limit <= 50 ms ok
    //ok wa so time limit is not a problem
    //
    int l = 0, r = N - 1;
    int best = 2e9;
    while (l < r) {
        while (r > l && A[l] + A[r] > target) { r--; }
        best = min(abs(target - (A[l] + A[r+1])), best);
        if (l < r) { best = min(target - (A[l] + A[r]), best); }
        l++;
    }
    cout << best << "\n";
}