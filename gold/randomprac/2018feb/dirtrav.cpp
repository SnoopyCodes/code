#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<vector<int>> dirs;
vector<ll> dists;
vector<int> subsize;
vector<int> len;
int filecnt = 0;

void first(int u) {
    for (int v : dirs[u]) {
        first(v);
        subsize[u] += subsize[v];
        dists[u] += dists[v] + subsize[v] * len[v];
    }
}

void second(int u, ll d) {
    for (int v : dirs[u]) {
        ll newd = (filecnt - subsize[v]) * 3 + d + dists[u] - len[v] * subsize[v] - dists[v];
        second(v, newd);
    }
    dists[u] += d;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("dirtraverse.in", "r", stdin);
    freopen("dirtraverse.out", "w", stdout);
    int N; cin >> N;
    dirs.resize(N);
    dists.resize(N);
    subsize.resize(N);
    len.resize(N);
    for (int i = 0; i < N; i++) {
        string nam; cin >> nam;
        len[i] = nam.size();
        int dir; cin >> dir;
        if (dir) {
            len[i]++;
            for (int j = 0; j < dir; j++) {
                int v; cin >> v; v--;
                dirs[i].push_back(v);
            }
        }   else {
            filecnt++;
            subsize[i] = 1;
        }
    }

    first(0);
    second(0, 0);

    cout << *min_element(dists.begin(), dists.end());
}