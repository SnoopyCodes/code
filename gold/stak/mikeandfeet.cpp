#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    vector<int> strength(N + 1); //with size i
    //so uh
    //thinking
    //is hard
    //uhhhh so
    //if we maintain the stack
    vector<array<int, 2>> st;
    //if we maintain the stack
    //we can find the longest a certain value can extend!
    for (int i = 0; i < N; i++) {
        while (!st.empty() && st.back()[0] >= v[i]) {
            st.pop_back();
        }
        int far;
        if (st.empty()) { far = -1; }
        else {
            far = st.back()[1];
        }
        strength[i - far] = max(strength[i - far], v[i]);
        st.push_back({v[i], i});
    }
    reverse(v.begin(), v.end());
    st.clear();
    for (int i = 0; i < N; i++) {
        while (!st.empty() && st.back()[0] >= v[i]) {
            st.pop_back();
        }
        int far;
        if (st.empty()) { far = -1; }
        else {
            far = st.back()[1];
        }
        strength[i - far] = max(strength[i - far], v[i]);
        st.push_back({v[i], i});
    }

    strength[N] = *min_element(v.begin(), v.end());
    int prev = 0;
    for (int i = N; i > 0; i--) {
        strength[i] = max(strength[i], prev);
        prev = strength[i];
    }
    for (int i = 1; i < N + 1; i++) {
        cout << strength[i] << " \n"[i == N];
    }
}