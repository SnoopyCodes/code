#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    //what if we were to find for each bear, the strength if it is the minimum?
    auto sweep = [&]() {
        vector<int> res(N);
        //mono stack
        stack<array<int, 2>> st; st.push({0, -1});
        for (int i = 0; i < N; i++) {
            while (v[i] <= st.top()[0]) { st.pop(); }
            res[i] = st.top()[1];
            st.push({v[i], i});
        }
        return res;
    };
    vector<int> left = sweep();
    reverse(v.begin(), v.end());
    vector<int> right = sweep();
    reverse(right.begin(), right.end());
    //these represent, therefore, untouchable bounds
    for (int i = 0; i < N; i++) {
        right[i] = N - right[i] - 1;
    }
    vector<int> ans(N + 1);
    reverse(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        int idx = right[i] - left[i] - 1;
        ans[idx] = max(ans[idx], v[i]);
    }
    int best = 0;
    for (int i = N; i > 0; i--) {
        ans[i] = max(best, ans[i]);
        best = max(best, ans[i]);
    }
    for (int i = 1; i < N + 1; i++) {
        cout << ans[i] << " \n"[i == N];
    }
}