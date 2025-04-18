#include <bits/stdc++.h>

#define vec vector

using namespace std;

vec<int > stick;
vec<bool> used;
vec<bool> old;
int len, total, N;
//okay wait: for some reason, setting the first grouping that we find is not optimal..
//factorial complexity...
//we are setting each stick into a "group"
bool works(int step, int sum, int ck) {
    if (sum == len) { step++; sum = 0; ck = 0; }
    if (step == total / len - 1) { return true; }
    for (int i = ck; i < N; i++) {
        if (used[i]) { continue; }
        if (sum + stick[i] > len) { continue; }
        used[i] = true;
        if (works(step, sum + stick[i], i + 1)) { return true; }
        used[i] = false;
        if (sum == 0) { return false; }
        while (i + 1 < N && stick[i] == stick[i + 1]) { i++; }
    }
    return false;
}

void solve() {
    cin >> N;
    stick.resize(N);
    used.clear(); used.resize(N);
    total = 0;
    for (int i = 0; i < N; i++) {
        cin >> stick[i];
        total += stick[i];
    }
    sort(stick.begin(), stick.end());
    reverse(stick.begin(), stick.end());
    for (int i = stick[0]; i <= total; i++) {
        if (total % i != 0) { continue; }
        len = i;
        if (works(0, 0, 0)) { cout << len << endl; return; }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("in.txt", "r", stdin);
    int T; cin >> T; while(T--) { solve(); }
}