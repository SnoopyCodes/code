#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> cows;
vector<int> dsu;
int find(int i) {
    if (dsu[i] != i) {
        dsu[i] = find(dsu[i]);
    }
    return dsu[i];
}
void unite(int i, int j) {
    int ri = find(i);
    int rj = find(j);
    if (rand() % 2)
        dsu[ri] = rj;
    else
        dsu[rj] = ri;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    cows.resize(N);
    dsu.resize(K);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    for (int i = 0; i < K; i++) {
        dsu[i] = i;
    }
    int c = 0;
    ll t = 0;
    priority_queue<int> open;
    for (int i = 0; i < K; i++) {
        open.push(-i);
    }
    priority_queue<pair<ll, int>> times;
    while (c < N && !open.empty()) {
        times.push({-(t + cows[c]), -open.top()});
        open.pop();
        c++;
    }
    while (c < N) {
        t = -times.top().first;
        // cout << t << endl;
        open.push(times.top().second);
        times.pop();
        while (!times.empty() && t == -times.top().first) { open.push(times.top().second); times.pop(); }
        // cout << open.size() << endl;
        int prev = -1;
        while (!open.empty()) {
            int f = open.top();
            if (prev != -1)
            unite(prev, f);
            prev = f;
            times.push({-(t + cows[c]), f});
            open.pop();
            c++;
        }
        // cout << "\n";
    }
    //c == N
    t = -times.top().first;
    open.push(times.top().second);
    times.pop();
    while (!times.empty() && t == -times.top().first) { open.push(times.top().second); times.pop(); }
    int prev = -1;
    int a = -1;
    assert(open == 1);
    while (!open.empty()) {
        int f = open.top();
        a = f;
        if (prev != -1)
        unite(prev, f);
        prev = f;
        open.pop();
    }
    cout << t << "\n";
    int root = find(a);
    for (int i = 0; i < K; i++) {
        cout << (find(i) == root);
    }
}