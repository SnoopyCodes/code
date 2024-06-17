#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, M; cin >> N >> M;
    string s; cin >> s;
    //find the number of things missing
    vector<char> needs{'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    vector<int> has(7);
    for (int i = 0; i < needs.size(); i++) {
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == needs[i]) {
                has[i]++;
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < needs.size(); i++) {
        cnt += max(0, M - has[i]);
    }
    cout << cnt << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}