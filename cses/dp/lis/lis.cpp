#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    set<int> s;
    for (int i = 0; i < N; i++) {
        if (s.count(arr[i])) { continue; }
        if (s.upper_bound(arr[i]) == s.end()) {
            s.insert(arr[i]);
        }   else {
            s.erase(s.upper_bound(arr[i]));
            s.insert(arr[i]);
        }
    }
    cout << s.size();
}