#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    //i think this problem is actually so peak
    //okay so use a stack like they said
    //for each point we want the closest smallest height
    //but we can't really pop off some of the other stuff
    //because those might also be nearest smaller elements.?
    //okay so we have on one side
    //then we can do the other side
    vector<int> ks(N);
    vector<long long> areas(N);
    stack<pair<int, int>> st;
    long long most = 0;
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        ks[i] = k;
        while (!st.empty() && st.top().first >= k) { st.pop(); }
        if (!st.empty()) {
            areas[i] = (long long) k * (i - st.top().second);
        }   else {
            areas[i] = (long long) k * (i+1);
        }
        // cout << k << " " << areas[i] << "\n";
        st.push({k, i});
    }
    // cout << "\n";
    while (!st.empty()) { st.pop(); }
    for (int i = N-1; i >= 0; i--) {
        int k = ks[i];
        while (!st.empty() && st.top().first >= k) { st.pop(); }
        if (!st.empty()) {
            areas[i] += (long long) k * (st.top().second - i - 1);
        }   else {
            areas[i] += (long long) k * (N - 1 - i);
        }
        // cout << k << " " << areas[i] << "\n";
        most = max(most, areas[i]);
        st.push({k, i});
    }
    cout << most << "\n";
}