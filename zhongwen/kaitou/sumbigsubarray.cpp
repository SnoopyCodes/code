#include <bits/stdc++.h>
#define long int64_t
using namespace std;

vector<int> A;
long answer = 0;
void solve(int l, int r) {
    if (l + 1 == r) { answer += A[l]; return; }
    int m = (l + r) / 2;
    solve(l, m);
    solve(m, r);
    int j = m;
    int most = A[m - 1];
    //suppose that the max comes from the left side
    for (int i = m - 1; i >= l; i--) {
        most = max(most, A[i]);
        while (j < r && A[j] <= most) { j++; }
        answer += (long) (j - m) * most;
    }
    j = m - 1;
    most = A[m];
    for (int i = m; i < r; i++) {
        most = max(most, A[i]);
        while (j >= l && A[j] < most) { j--; }
        answer += (long) (m - 1 - j) * most;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    A.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    //two ways to solve: one with monotonic stack, and one with dnc
    solve(0, N);
    cout << answer << "\n";

    // vector<int> cl(N), cr(N);
    // stack<int> st;
    // st.push(-1);
    // for (int i = 0; i < N; i++) {
    //     while (st.top() != -1 && A[st.top()] < A[i]) { st.pop(); }
    //     cl[i] = st.top();
    //     st.push(i);
    // }
    // while (!st.empty()) { st.pop(); }
    // st.push(N);
    // for (int i = N - 1; i > -1; i--) {
    //     while (st.top() != N && A[st.top()] <= A[i]) { st.pop(); }
    //     cr[i] = st.top();
    //     st.push(i);
    // }
    // long ans = 0;
    // for (int i = 0; i < N; i++) {
    //     ans += (long) (i - cl[i]) * (cr[i] - i) * A[i];
    // }
    // cout << ans << "\n";
}