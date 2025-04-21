#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
const int MOD = 1e9 + 7;
const i64 INF = 4e18 + 7e9;

#define rep(i,s,e) for(auto i=s;i<e;i++)
#define rev(i,s,e) for(auto i=s;i>e;i--)
#define emp emplace
#define emb emplace_back
#define pob pop_back

void solve() {
    int N; cin >> N;
    string s; cin >> s;
    //iterate from back
    int ind = 0;
    vector<int> pos(N);
    for (int i = N - 2; i > -1; i--) {
        if (s[i] == '<') { pos[i+1] = ind++; }
    }
    pos[0] = ind++;
    for (int i = 0; i < N - 1; i++) {
        if (s[i] == '>') { pos[i+1] = ind++; }
    }
    for (int i = 0; i < N; i++) {
        cout << pos[i] + 1 << " \n"[i == N - 1];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}