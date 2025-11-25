#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

void chain(int u, mt<int> &G, vt<int> &sum_down, vt<int> &sum_up, int d) {
    sum_up[u] += d; //can be placed at [d]
    if (size(G[u])) {
        chain(G[u][0], G, sum_down, sum_up, d + 1);
        sum_down[u] = sum_down[G[u][0]] + 1;
    }
}

void solve() {
    int N; cin >> N;
    string s; cin >> s;
    mt<int> G(N);
    vt<int> in(N), out(N), sum_up(N), sum_down(N);
    for (int i = 0; i < N - 1; i++) {
        if (s[i] == 'L') {
            G[i + 1].add(i);
            in[i]++;
        }   else {
            G[i].add(i + 1);
            in[i + 1]++;
        }
    }
    //now what?
    //indegree/outdegree of each <= 2
    //for each in[i] = 0
    //call it a source
    //for each out[i] = 09
    //call it a sink
    //and go sir go
    for (int i = 0; i < N; i++) {
        if (in[i] == 0) {
            chain(G[i][0], G, sum_down, sum_up, 1);
            sum_down[i] = 1 + sum_down[G[i][0]];
            if (size(G[i]) > 1) {
                chain(G[i][1], G, sum_down, sum_up, 1);
                sum_down[i] += 1 + sum_down[G[i][1]];
            }
        }
    }
    
    vt<int> da(N + 1);
    for (int i = 0; i < N; i++) {
        da[sum_up[i]]++;
        da[N - sum_down[i]]--;
    }
    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += da[i];
        cout << sum << " \n"[i == N - 1];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >>  T; while (T --> 0) { solve(); }
}