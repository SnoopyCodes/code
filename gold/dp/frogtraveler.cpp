#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> jumps(N);
    vector<int> slips(N);
    for (int i = 0; i < N; i++) {
        cin >> jumps[N - i - 1];
    }
    for (int i = 0; i < N; i++) {
        cin >> slips[N - i - 1];
    }
    vector<int> last(N + 1, -1);  //where we came from
    vector<int> preslip(N + 1, -1);
    last[0] = 0;
    int cover = 0;
    queue<int> q; q.push(0);
    while (!q.empty()) {
        int d = q.front();
        q.pop();
        if (d + jumps[d] <= cover) { continue; }
        for (int i = cover + 1; i < N && i <= d + jumps[d]; i++) {
            if (last[i - slips[i]] != -1) { continue; }
            last[i - slips[i]] = d;
            preslip[i - slips[i]] = i;
            q.push(i - slips[i]);
        }
        if (d + jumps[d] >= N) {
            preslip[N] = N;
            last[N] = d;
            break;
        }
        cover = d + jumps[d];
    }
    vector<int> v;
    int cur = N;
    if (last[cur] == -1) { cout << -1 << "\n"; return 0; }
    while (cur != 0) {
        v.push_back(-(preslip[cur] - N));
        cur = last[cur];
    }
    reverse(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " \n"[i == v.size() - 1];
    }

}