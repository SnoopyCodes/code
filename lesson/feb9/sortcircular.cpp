#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vector<int> circle(N);
    for (int i = 0; i < N; i++) {
        cin >> circle[i];
    }
    //literally brute force
    //100 * 1e5 * 18
    //1e7 * 18 -> 1.7e8
    //probably OK
    for (int q = 0; q < Q; q++) {
        int k, l; cin >> k >> l;
        vector<int> to_sort;
        for (int i = k; i < k + l; i++) {
            to_sort.push_back(circle[i % N]);
        }
        sort(to_sort.begin(), to_sort.end());
        for (int i = k; i < k + l; i++) {
            circle[i % N] = to_sort[i - k];
        }
    }
    cout << circle[0] << "\n";
}