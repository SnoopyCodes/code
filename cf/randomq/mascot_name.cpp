#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;
#define long long long
const int MOD = 1e9 + 7;
const long INF = 4e18;

#define rep(i,s,e) for(auto i=(s);i<(e);i++)
#define rev(i,s,e) for(auto i=(s) - 1;i>=(e);i--)
#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back

template<typename T> using max_heap = std::priority_queue<T>;
template<typename T> using min_heap = std::priority_queue<T, vector<T>, std::greater<T>>;
template <typename T> T mvec(T def) { return def; }
template <typename T, typename...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }
template<class T,class... A>auto ta(T f,A...r)->array<T, sizeof...(A)+1>{return {f, r...};}


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<std::string> req(N);
    vector<int> at(N);
    std::string bad;
    std::set<char> ok;
    std::map<char, vector<int>> in;
    for (int i = 0; i < N; i++) {
        cin >> req[i];
        ok.emp(req[i][0]);
        in[req[i][0]].push_back(i);
    }
    cin >> bad;
    std::string ans = "";

    int ind_bad = 0;
    int count = 0;
    
    while (count < N) {
        char c = *ok.begin();
        char no = bad[ind_bad];
        if (c == no && ok.size() == 1) {
            ind_bad++;
        }   else if (c == no){
            c = *--ok.end();
        }
        ans += c;
        ok.erase(c);
        if (ind_bad == bad.size()) { break; }

        vector<int> dep = in[c];
        in.erase(c);
        for (int x : dep) {
            at[x]++;
            if (at[x] < req[x].size()) {
                ok.emp(req[x][at[x]]);
                in[req[x][at[x]]].push_back(x);
            }   else {
                count++;
            }
        }
    }
    if (ind_bad == bad.size()) { cout << "NO" << "\n"; }
    else {
        cout << "YES" << "\n";
        cout << ans << "\n";
    }
}