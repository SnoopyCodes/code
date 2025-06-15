#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;
#define long long long
const int MOD = 1e9 + 7;
const long INF = 4e18;

#define rsz resize

template<typename T> using max_heap = std::priority_queue<T>;
template<typename T> using min_heap = std::priority_queue<T, vector<T>, std::greater<T>>;
template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }
template<class T,class... A>auto ta(T f,A...r)->array<T, sizeof...(A)+1>{return {f, r...};}

void solve() {
    int N, Q; cin >> N >> Q;
    //0, 1, or 2
    //obviously, we must solve it offline.
    //we want to move "a" as forward as possible
    //we can get the frequency of 'a' at any time
    //and essentially we want to move 'a' to the beginning as much as possible
    //we want to "keep" "good" updates
    //and override "bad" updates
    vector<int> string(N);
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        int x = c - 'a';
        string[i] = x;
    }
    //1-0, 2-0, 2-1; 0-1 0-2 1-2
    array<std::set<int>, 6> delta{};
    for (int q = 0; q < Q; q++) {
        char x, y; cin >> x >> y;
        if (x == y) { continue; }
        int xx = x - 'a', yy = y - 'a';
        delta[xx + yy - 1 + (xx < yy ? 3 : 0)].insert(q);
    }
    for (int i = 0; i < N; i++) {
        //make this character as large as we can
        if (string[i] == 0) { cout << 'a'; continue; }
        else if (string[i] == 1) {
            //1-0 [0]
            if (delta[0].size()) {
                delta[0].erase(delta[0].begin());
                cout << 'a';
            }   else {  //1-2, 2-0 [5], [1]
                if (delta[5].size()) {
                    int t = *delta[5].begin();
                    if (delta[1].lower_bound(t) != delta[1].end()) {
                        delta[5].erase(delta[5].begin());
                        delta[1].erase(delta[1].lower_bound(t));
                        cout << 'a';
                    }   else {
                        cout << 'b';
                    }
                }   else {
                    cout << 'b';
                }
            }
        }   else {
            if (delta[1].size()) {  //2-0 [1]
                delta[1].erase(delta[1].begin());
                cout << 'a';
            }   else if (delta[2].size()) { //2-1 1-0 [2] [0]
                int t = *delta[2].begin();
                if (delta[0].lower_bound(t) != delta[0].end()) {
                    delta[2].erase(delta[2].begin());
                    delta[0].erase(delta[0].lower_bound(t));
                    cout << 'a';
                }   else {  //2-1 [2]
                    delta[2].erase(--delta[2].end());
                    cout << 'b';
                }
            }   else {
                cout << 'c';
            }
        }
    }
    cout << "\n";

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}