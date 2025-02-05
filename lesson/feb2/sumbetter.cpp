#include <bits/stdc++.h>
#define long int64_t
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("in.txt", "r", stdin);
    int N; cin >> N;
    vector<int> A(N);
    vector<queue<int>> qs(N + 2);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        qs[A[i]].push(i);
    }
    for (int i = 1; i <= N + 1; i++) {
        qs[i].push(N);
    }
    vector<int> cl(N), cr(N);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < N; i++) {
        while (st.top() != -1 && A[st.top()] < A[i]) { st.pop(); }
        cl[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) { st.pop(); }
    st.push(N);
    for (int i = N - 1; i > -1; i--) {
        while (st.top() != N && A[st.top()] <= A[i]) { st.pop(); }
        cr[i] = st.top();
        st.push(i);
    }
    //we know where it is max.
    //num subarrays where it does not find A[i] + 1 - num subarrays where it is max
    long ans = 0;
    map<int, int> last;
    for (int i = 0; i < N; i++) {
        qs[A[i]].pop();
        int l;
        int r = min(qs[A[i] + 1].front(), qs[A[i]].front());
        if (!last.count(A[i] + 1)) {
            l = -1;
        }   else {
            l = last[A[i] + 1];
        }
        ans += (long) (i - l) * (r - i);
        ans -= (long) (i - cl[i]) * (cr[i] - i);
        // cout << l << " " << r << "\n";
        // cout << cl[i] << " " << cr[i] << "\n";
        // cout << ans << "\n";
        // cout << "\n";
        last[A[i]] = i;
    }
    cout << ans % MOD << "\n";
}