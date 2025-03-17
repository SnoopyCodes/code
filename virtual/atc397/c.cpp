#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;
using i64 = long long;
const i64 INF = 4e18 + 7e9;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vec<int> A(N);
    map<int, int> left, right;
    rep(i, N) {
        cin >> A[i];
        if (i < N - 1) left[A[i]]++;
        else right[A[i]]++;
    }
    int ans = left.size() + right.size();
    rep(i, -(N - 1)) {
        left[A[i]]--;
        if (left[A[i]] == 0) { left.erase(A[i]); }
        right[A[i]]++;
        ans = max(ans, int(left.size() + right.size()));
    }
    cout << ans << "\n";
}