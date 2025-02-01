#include <bits/stdc++.h>

using std::cin;
using std::vector;
using std::max;
using std::cout;

vector<int> P, count;
int answer = 0;
void solve(int l, int r) {
    if (l + 1 == r) { return; }  //we can't possibly be 2x ourselves
    int m = (l + r) / 2;
    solve(l, m);
    solve(m, r);
    //suppose the max comes from the left
    int most = 0;
    int j = m;
    for (int i = m - 1; i >= l; i--) {
        most = max(most, P[i]);
        while (j < r && P[j] < most) { count[P[j]]++; j++; }
        answer += count[most - P[i]];
    }
    for (int i = m; i < r; i++) {
        count[P[i]] = 0;
    }

    most = 0;
    j = m - 1;
    for (int i = m; i < r; i++) {
        most = max(most, P[i]);
        while (j >= l && P[j] < most) { count[P[j]]++; j--; }
        answer += count[most - P[i]];
    }
    for (int i = l; i < m; i++) {
        count[P[i]] = 0;
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //special segments of permutation
    int N; cin >> N;
    P.resize(N), count.resize(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }
    //enact a divide and conquer
    solve(0, N);
    cout << answer << "\n";
}