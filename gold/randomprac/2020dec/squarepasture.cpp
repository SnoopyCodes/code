#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vec<arr<int, 2>> cows(N);
    int maxx = 0, maxy = 0;
    rep(i, N) {
        cin >> cows[i][0] >> cows[i][1];
    }
    if (N <= 22) {
        int ans = 1;
        rep(mask, 1, 1 << N) {
            maxx = 0, maxy = 0;
            int minx = 1e9, miny = 1e9;
            rep(b, N) {
                if (mask & 1 << b) {
                    maxx = max(maxx, cows[b][0]);
                    minx = min(minx, cows[b][0]);
                    maxy = max(maxy, cows[b][1]);
                    miny = min(miny, cows[b][1]);
                }
            }
            int len = max(maxx - minx, maxy - miny);  //square length
            bool ok = true;
            //all bounds inclusive, i think
            int lfb = maxx - len, rb = minx + len;
            int ub = miny + len, lb = maxy - len;
            rep(b, N) {
                if (!(mask & 1 << b)) {
                    auto [x, y] = cows[b];
                    //we can maintain bounds on where this is forced to go to not include this
                    if (minx <= x && x <= maxx && miny <= y && y <= maxy) { ok = false; }
                    //if it is in x-zone
                    if (minx <= x && x <= maxx) {
                        if (y > maxy) { ub = min(ub, y - 1); }
                        if (y < miny) { lb = max(lb, y + 1); }
                    }   else if (miny <= y && y <= maxy) {
                        if (x > maxx) { rb = min(rb, x - 1); }
                        if (x < minx) { lfb = max(lfb, x + 1); }
                    }
                }
            }
            ans += ok && lfb <= rb - len && lb <= ub - len;
        }
        cout << ans << "\n";
    }   else if (maxx <= 25 && maxy <= 25) {
        set<int> s;
        rep(sl, 1, 51) {
            rep(i, -25, 25) {
                rep(j, -25, 25) {
                    int mask = 0;
                    for (int b = 0; b < N; b++) {
                        auto [x, y] = cows[b];
                        if (i <= x && x <= i + sl && j <= y && y <= j + sl) {
                            mask += 1 << b;
                        }
                    }
                    s.insert(mask);
                }
            }
        }
        cout << s.size() << "\n";
    }   else {
        cout << "i give up" << "\n";
    }
}