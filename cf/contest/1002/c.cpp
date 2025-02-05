#include <bits/stdc++.h>
#define long int64_t
using namespace std;

void solve() {
    int N; cin >> N;
    vector<vector<int>> add(N, vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> add[i][j];
        }
    }
    vector<int> best(N);
    for (int i = 0; i < N; i++) {
        int sum = 0;
        bool v = true;
        for (int j = N - 1; j > -1; j--) {
            if (add[i][j] == 1) { sum++; }
            else { best[i] = sum; v = false; break; }
        }
        if (v)
        best[i] = N;
    }
    sort(best.begin(), best.end());
    int d = 0;
    while (d < N && best[d] == 0) { d++; }
    //whoo boy maximum mex time
    //we must ensure that one queue has 0
    //then one queue has one
    //wait each queue might have a certain amount
    //this is a lot easier than B?
    //find a queue with pf sum backwards >= i
    //binary search on it ngl
    //wait i am a stupid
    //average silver suffering from binary search overuse
    //look
    //at the last time, we have to 
    int s = 0, e = N;
    //the last one that we have <= that for
    while (s + 1 < e) {
        int m = (s + e) / 2;
        int count = 0;
        vector<int> counts(N + 1);
        //sum the ones >= m
        int i = N - 1;
        for (; best[i] > m && i > -1; i--) {
            count++;
        }
        for (int j = 0; j < N; j++) {
            counts[best[j]]++;
        }
        bool valid = true;
        for (i = m; i > -1; i--) {
            count += counts[i];
            count--;
            if (count < 0) { valid = false; }
        }
        if (valid) { s = m; }
        else { e = m; }
    }
    cout << s + 1 << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}