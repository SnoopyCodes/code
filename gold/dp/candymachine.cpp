#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
using i64 = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vec<arr<int, 4>> candy(N);
    rep(i, N) {
        int s, t; cin >> s >> t;
        candy[i] = {s - t, s + t, i, 0};
    }
    //min amount of points to cover all endpoints
    //the min wagons is longest sequence of non-nested ranges
    //once we sort by left endpoint, it becomes a lis on right endpoints! wtf damn
    sort(candy.begin(), candy.end(), [](arr<int, 4> &a, arr<int, 4> &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    });
    vec<int> lis;
    for (auto &[l, r, i, a] : candy) {
        int ind = lower_bound(lis.begin(), lis.end(), r) - lis.begin();
        if (ind == lis.size()) { lis.push_back(r); }
        else { lis[ind] = r; }
        a = ind + 1;
    }
    sort(candy.begin(), candy.end(), [](arr<int, 4> &a, arr<int, 4> &b) {
        return a[2] < b[2];
    });
    cout << lis.size() << "\n";
    for (auto const&[l, r, i, a] : candy) {
        cout << (l + r) / 2 << " " << (r - l) / 2 << " " << a << "\n";
    }
}