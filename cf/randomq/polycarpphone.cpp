#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vt<string> str(N);
    unordered_map<string, int> m;
    for (int i = 0; i < N; i++) {
        cin >> str[i];
        for (int l = 0; l < 9; l++) {
            for (int r = l; r < 9; r++) {
                m[str[i].substr(l, r - l + 1)]++;
            }
        }
    }
    /*
    why are we using a trie?
    sort them.
    just binary search.
    kid named reading comprehension:
    */

    for (int i = 0; i < N; i++) {
        bool done = false;
        for (int l = 0; l < 9; l++) {
            for (int r = l; r < 9; r++) {
                m[str[i].substr(l, r - l + 1)]--;
            }
        }
        for (int len = 1; len <= 9; len++) {
            for (int start = 0; start <= 9 - len; start++) {
                if (m[str[i].substr(start, len)] == 0) {
                    done = true;
                    cout << str[i].substr(start, len) << "\n";
                    break;
                }
            }
            if (done) break;
        }
        for (int l = 0; l < 9; l++) {
            for (int r = l; r < 9; r++) {
                m[str[i].substr(l, r - l + 1)]++;
            }
        }
    }

}