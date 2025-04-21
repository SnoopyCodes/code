#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
const int MOD = 1e9 + 7;
const i64 INF = 4e18 + 7e9;

#define rep(i, s, e) for (auto i = s; i < e; i++)
#define rev(i, s, e) for (auto i = s - 1; i >= e; i--)
#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back

void solve() {
    int N, K; cin >> N >> K;
    //binary search
    string str; cin >> str;
    int cur = str[N - 1] == '1' ? 1 : -1;
    i64 score = str[N - 1] == '1' ? N - 1 : -(N - 1);
    multiset<int> s;
    rev(i, N - 1, 0) {
        score += str[i] == '1' ? i : -i;
        // cout << cur << "\n";
        s.insert(cur);
        cur += str[i] == '1' ? 1 : -1;
    }
    //divide it into m groups
    //the contribution of a group is (B - A) * i for each group
    //we want net to be >= K
    //B - A = B - (len - B) = 2 B - len
    //start with the initial array
    //we have a score
    //and we can "extend" things
    //we can only extend a group rightwards
    //in doing so we decrease the score of everything to the right
    //by 1?
    //1 2 3 4 5
    //2-3 so it becomes 1 2-2 3 4, decreasing score by suffix
    //and we can do this once per index
    //wow very good greedy i like this problem
    while (!s.empty()) {
        int d = *s.begin();
        if (score >= K) {
            if (score - d < K) { break; }
        }
        s.erase(s.find(d));
        score -= d;
    }
    if (score >= K) { cout << s.size() + 1 << "\n"; }
    else { cout << -1 << "\n"; }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}