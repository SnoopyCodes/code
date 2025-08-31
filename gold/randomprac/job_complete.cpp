#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int, z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using vv = vt<vt<T>>;

void solve() {
    int N; cin >> N;
    vt<ll<2>> j_bs(N);
    for (int i = 0; i < N; i++) {
        cin >> j_bs[i][0] >> j_bs[i][1];
        j_bs[i][0] += j_bs[i][1];
    }
    sort(j_bs.begin(), j_bs.end()); //hey usaco you should allow c++ 20 for ranges::sort
    priority_queue<long> sel__j_bs;
    long time = 0;
    for (auto [d, t] : j_bs) {
        sel__j_bs.push(t);
        time += t;
        if (time > d) {
            time -= sel__j_bs.top();
            sel__j_bs.pop();
        }
    }
    set<int> s;
    cout << sel__j_bs.size() << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}