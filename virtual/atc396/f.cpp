#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;

using i64 = long long;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#define rat order_of_key  //find how many less than element
#define at find_by_order //iterator to the kth element, [] essentially
template<typename T> using gset = gp_hash_table<T, null_type>;
template<typename K, typename V> using gmap = gp_hash_table<K, V>;

template <class T>
using iset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, M; cin >> N >> M;
    //make time changes and iterate through to calculate
    iset<arr<int, 2>> is;
    i64 ans = 0;
    vec<vec<int>> change(M+1);
    vec<int> ligv(N);  //less index greater val
    vec<int> lilv(N), gilv(N), gigv(N);
    vec<int> A(N);
    rep(i, N) {
        cin >> A[i];
    }
    rep(i, N) {
        int x = A[i];
        change[M - x].push_back(i);
        ligv[i] = is.size() - is.rat({x, i});
        lilv[i] = is.rat({x, -1});
        is.insert({x, i});
    }
    is.clear();
    rep(i, -N) {
        gilv[i] = is.rat({A[i], -1});
        gigv[i] = is.size() - is.rat({A[i], N});
        ans += gilv[i];
        is.insert({A[i], i});
    }
    rep(i, 0, M) {
        for (auto j : change[i]) {
            ans -= gilv[j];
            ans += ligv[j];
            ans += lilv[j];
            ans -= gigv[j];
        }
        cout << ans << "\n";
    }
}