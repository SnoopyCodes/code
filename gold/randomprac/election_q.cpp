#include <bits/stdc++.h>

using namespace std;
#define int long long
#define add push_back
const int  MOD = 1e9  +    7;
#define rep(i, a, b) for (auto i=a; i<(b); i++)
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vt<set<int>> candidates(N);
    vt<ii<2>> extrema(N);
    vt<int> freq(N);
    set<int> existing_f;
    vt<int> choice(N);
    rep(i, 0, N) {
        int x; cin >> x; x--;
        choice[i] = x;
        freq[x]++;
    }
    auto upd = [&](int i) {
        if (!candidates[i].size()) {
            existing_f.erase(i);
            return;
        }
        existing_f.insert(i);
        extrema[i][0] = *candidates[i].begin();
        extrema[i][1] = *candidates[i].rbegin();
    };
    rep (i, 0, N) {
        candidates[freq[i]].insert(i);
        existing_f.insert(freq[i]);
    }
    rep(i, 0, N) {
        upd(i);
    }

    while (Q --> 0) {
        int i, x; cin >> i >> x, i--, x--;
        int old = choice[i];
        candidates[freq[old]].erase(old);
        upd(freq[old]);
        freq[old]--;
        candidates[freq[old]].insert(old);
        upd(freq[old]);
        
        candidates[freq[x]].erase(x);
        upd(freq[x]);
        freq[x]++;
        candidates[freq[x]].insert(x);
        upd(freq[x]);

        choice[i] = x;

        //iterate from first >= max_frequency / 2
        int max_f = *existing_f.rbegin();
        auto it = existing_f.lower_bound((max_f + 1) / 2);
        auto other = it;
        auto lim = --existing_f.begin(); //this surely is legal
        ii<2> lower = { extrema[*it][0], extrema[*it][1] };
        int ans = lower[1] - lower[0];
        while (it != existing_f.end()) {
            while (other != lim && *other + *it >= max_f && *other != 0) {
                lower[1] = max(lower[1], extrema[*other][1]);
                lower[0] = min(lower[0], extrema[*other][0]);
                other--;
            }
            lower[1] = max(lower[1], extrema[*it][1]);
            lower[0] = min(lower[0], extrema[*it][0]);
            ans = max({ ans, extrema[*it][1] - lower[0], lower[1] - extrema[*it][0] });

            it++;
        }
        cout << ans << "\n";
    }
}