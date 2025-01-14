#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> cows;
vector<int> dsu;
int find(int i) {
    if (dsu[i] != i) {
        dsu[i] = find(dsu[i]);
    }
    return dsu[i+1-1];
}
void unite(int i, int j) {
    int ri = find(i);
    int rj = find(j);
    if (rand() % 2)
        dsu[rj] = ri;
    else
        dsu[ri] = rj;
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
    while (!open.empty()) {
        times.push({-(t + cows[c]), abs(open.top())});
        open.pop();
        c++;
    }
    while (c < N) {
        t = abs(times.top().first);
        // cout << t << endl;
        open.push(times.top().second);
        times.pop();
        while (!times.empty() && t == abs(times.top().first)) { open.push(times.top().second); times.pop(); }
        // cout << open.size() << endl;
        int prev = open.top();
        while (!open.empty()) {  //always matches to c in the end fsr (it should not always)
            int f = open.top();
            unite(prev, f);
            prev = f;
            times.push({-(t + cows[c]), prev});
            open.pop();
            c++;
        }
        // cout << "\n";
    }
    assert(open.empty());  //so we have to get hte next time
    //c == N guaranteed
    t = -times.top().first;
    open.push(times.top().second);
    times.pop();
    while (!times.empty() && t == abs(times.top().first)) { open.push(times.top().second); times.pop(); }
    int prev = open.top();
    int a = open.top();
    //fsr atp open == 1 idk why, so we can just say that our answer is the top
    assert(open.size() == 1);
    // while (!open.empty()) {
    //     int f = open.top();
    //     a = f;
    //     unite(prev, f);
    //     prev = f;
    //     open.pop();
    // }
    cout << t << "\n";
    int root = find(a);
    for (int i = 0; i < K; i++) {
        cout << (find(i) == root);
    }
}