#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    //you can say for each prefix which ones it will have in O(1) time, if you precompute it
    int N; cin >> N;
    int total = 0;
    set<string> vocab;
    for (int q = 0; q < N; q++) {
        int query; cin >> query;
        if (query == 1) {
            string s; cin >> s;
            vocab.insert(s);
        }   else {
            string s; cin >> s;
            const auto &p1 = vocab.lower_bound(s);
            s = s.substr(0, s.size()-1) + (char) (s[s.size()-1] + 1);
            const auto &p2 = vocab.lower_bound(s);
            total += distance(p1, p2);
        }
    }
    cout << total << "\n";
}