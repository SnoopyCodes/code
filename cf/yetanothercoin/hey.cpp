#include <bits/stdc++.h>
//failure, counting is hard
using namespace std;
vector<int> coins{1, 3, 6, 10, 15};
vector<int> possible(16, INT_MAX);
int run(int x) {
    if (x < 0) { return -1; }
    if (possible[x] != INT_MAX) { return possible[x]; }
    for (int c : coins) {
        int moves = run(x - c) + 1;
        if (moves <= 0) { continue; }
        possible[x] = min(possible[x], moves);
    }
    return possible[x];
}
void solve() {
    int N; cin >> N;
    int res = N % 15;
    int times = (N - 15) > 0 ? ((N - 15) / 15) : 0;
    cout << times + possible[res] << "\n";
    //a normal dp is too slow
    //or is it?
    //help what do i do
    //
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    possible[0] = 0;
    run(15);
    int T; cin >> T; while (T) { T--; solve(); }
}