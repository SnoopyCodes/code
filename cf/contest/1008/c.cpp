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

void solve() {
    int N; cin >> N;
    N = 2 * N;
    vec<i64> B(N);
    set<i64> s, rems;
    rep(i, N) {
        cin >> B[i];
        s.insert(B[i]);
        rems.insert(B[i]);
    }
    //...
    //all numbers are distinct so have difference with each other
    //can we just find a couple to swap and see if it works?
    //given some x, is there a way to make b[i] know how to do this crap
    //not knapsack... dp?
    //why am i so bad
    //surely if we sort and go then it works as well
    B.clear();
    rep(i, N) {
        if (i % 2 == 0) {
            B.push_back(*--rems.end());
            rems.erase(--rems.end());
        }   else {
            B.push_back(*rems.begin());
            rems.erase(rems.begin());
        }
    }

    i64 e = 0;
    rep(i, N) {
        if (i % 2 == 0) { e += B[i]; }
        else { e -= B[i]; }
    }

    for (int i = 0; i < N; i += 2) {
        if (!s.count(abs(e - 2 * (B[i] - B[i+1])))) {
            e -= 2 * (B[i] - B[i+1]);
            swap(B[i], B[i+1]);
            break;
        }
    }
    if (!s.count(abs(e))) {
        if (e > 0)
        reverse(B.begin(), B.end());
        B.push_back(abs(e));
        rep(i, B.size()) {
            cout << B[i] << " \n"[i == N];
        }
    }   else {
        sort(B.begin(), B.end());
        reverse(B.begin(), B.end());
        e = 0;
        rep(i, N) {
            if (i % 2 == 0) { e += B[i]; }
            else { e -= B[i]; }
        }
        for (int i = 0; i < N; i += 2) {
            if (!s.count(abs(e - 2 * (B[i] - B[i+1])))) {
                e -= 2 * (B[i] - B[i+1]);
                swap(B[i], B[i+1]);
                break;
            }
        }
        if (e > 0) { reverse(B.begin(), B.end()); }
        B.push_back(abs(e));
        rep(i, B.size()) {
            cout << B[i] << " \n"[i == N];
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}