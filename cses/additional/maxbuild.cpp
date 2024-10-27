#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //prefix sums doesn't work
    //suppose we start with base at 0 and slide window or something
    //start with the leftmost index
    //no way its N^3 ok its not
    //wait why does dsu work tf
    //well it should be the same thing
    //hmm
    int N, M; cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            grid[i][j] = s[j] == '*';
        }
    }
    vector<int> v = grid[0];
    auto count = [&]() {
        int best = 0;
        int last = -1;
        for (int i = 0; i < M; i++) {
            if (v[i]) { best = max(i - last - 1, best); last = i; }
        }
        best = max(M - last - 1, best);
        return best;
    };
    int ans = count();
    auto queue = [&](int x) {
        for (int i = 0; i < M; i++) {
            v[i] += grid[x][i];
        }
    };
    auto dequeue = [&](int x) {
        for (int i = 0; i < M; i++) {
            v[i] -= grid[x][i];
        }
    };
    for (int l = 0, r = 1; r < N; r++) {
        cout << l << " " << r << "\n";
        //process r
        queue(r);
        //find the longest segment of contiguous 0's
        int cur = count() * (r - l + 1);
        ans = max(ans, cur);
        //while removing is better, remove
        dequeue(l); l++;
        int possible = count() * (r - l + 1);
        for (int i = 0; i < M; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        while (l <= r && cur <= possible) {
            cout << cur << " " << possible << "\n";
            cur = possible;
            
            ans = max(possible, ans);
            //remove
            dequeue(l); l++;
            possible = count() * (r - l + 1);
        }
        l--; queue(l);
        ans = max(possible, ans);
        cout << "\n";
    }
    cout << ans << "\n";
}