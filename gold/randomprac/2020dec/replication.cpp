#include <bits/stdc++.h>

using namespace std;

#define MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

template<typename T> using vec = vector<T>;
template<typename T, int a> using arr = array<T, a>;

const arr<int, 4> dr {-1, 1, 0, 0}, dc{0, 0, -1, 1};

vec<arr<int, 2>> around(int r, int c, int rad) {
    vec<arr<int, 2>> res;
    if (rad == 0) { return {{r, c}}; }
    rep(i, rad) {
        rep(j, 4) {
            int sr, sc;
            if (j == 0) {
                sr = r + rad - i;
                sc = c - i;
            }   else if (j == 1) {
                sr = r - rad + i;
                sc = c + i;
            }   else if (j == 2) {
                sc = c + rad - i;
                sr = r + i;
            }   else {
                sc = c - rad + i;
                sr = r - i;
            }
            res.push_back({sr, sc});
        }
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, D; cin >> N >> D;
    vec<vec<char>> farm(N, vec<char>(N));
    vec<vec<bool>> vis(N, vec<bool>(N));
    queue<arr<int, 3>> q;
    rep(i, N) {
        rep(j, N) {
            cin >> farm[i][j];
            if (farm[i][j] == 'S') {
                vis[i][j] = true;
                q.push({i, j, 0});
            }
        }
    }
    auto ob = [&](int r, int c) {
        return r < 0 || c < 0 || r >= N || c >= N || (farm[r][c] == '#');
    };
    
    while (!q.empty()) {
        //center, time that we arrive (smaller always better)
        auto [cr, cc, t] = q.front(); q.pop();
        int rad = t / D;
        bool plus = (t + 1) % D == 0;
        set<arr<int, 2>> s;  //actually new stuff
        rep(d, 4) {
            vec<arr<int, 2>> next;  //the new ones we find
            bool bad = false;
            int nr = cr + dr[d];  //new center we move to
            int nc = cc + dc[d];
            vec<arr<int, 2>> check = around(nr, nc, rad);  //default check
            for (auto [r, c] : check) {
                if (ob(r, c)) { bad = true; break; }
                if (!vis[r][c]) { next.push_back({r, c}); }
            }
            if (bad || next.empty() && !plus) { continue; }
            //make movement
            for (auto [r, c] : next) {  //we can make this movement
                s.insert({r, c});
            }
            if (plus) {
                next.clear();
                check = around(nr, nc, rad + 1);
                for (auto [r, c] : check) {
                    if (ob(r, c)) { bad = true; }
                    if (!vis[r][c]) { next.push_back({r, c}); }
                }
                if (bad) { continue; }
                for (auto [r, c] : next) {
                    s.insert({r, c});
                }
            }
            if (next.size())
            q.push({nr, nc, t + 1});
        }
        for (auto [r, c] : s) {
            vis[r][c] = true;
        }
    }
    int ans = 0;
    rep(i, N) {
        rep(j, N) {
            ans += vis[i][j];
        }
    }
    cout << ans << "\n";
}