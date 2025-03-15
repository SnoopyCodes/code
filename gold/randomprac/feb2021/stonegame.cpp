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
    vec<int> pile(N);
    rep(i, N) {
        cin >> pile[i];
    }
    int MAXV = *max_element(pile.begin(), pile.end());
    vec<int> ge(MAXV+1);  //number of numbers >= i
    rep(i, N) {
        ge[pile[i]]++;
    }
    rep(i, -MAXV) {
        ge[i] += ge[i+1];
    }
    i64 ans = 0;
    rep(i, 1, MAXV + 1) {
        vec<int> amts;
        for (int j = i; j <= MAXV; j += i) {
            int amt = ge[j] - (j + i > MAXV ? 0 : ge[j + i]);
            amts.push_back(amt);
        }
        //if all are even except the first, we can remove from first
        //otherwise, if there are only 2 consecutive odds, we can remove from the second odd
        //otherwise, not ok

        // if (i == 1) {
        // for (int x : amts) {
        //     cout << x << " ";
        // }
        // cout << "\n";}
        int con = 0;
        int odd = amts.back() % 2 == 1;
        rep(j, amts.size() - 1) {
            if (amts[j] % 2 == 1) { odd++; }
            if (amts[j] % 2 == 1 && amts[j+1] % 2 == 1) {
                if (con) { con = -1; break; }
                con = j + 1;
            }
        }
        if (odd > 2 || odd == 1 && amts[0] % 2 == 0 || odd == 2 && con == 0) { continue; }
        if (!con && amts[0] % 2 != 1) { continue; }
        // cout << i << " " << amts[con] << "\n";
        ans += amts[con];
    }
    cout << ans << "\n";
}