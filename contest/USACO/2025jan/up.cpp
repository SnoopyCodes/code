#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))

const long INF = 4e18 + 7e9;

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    if (N == 1) { cout << 2 << endl; return 0;}
    vec<vec<int>> grid(N, vec<int>(N));
    vec<int> appear(2 * N + 1);
    rep(i, N) {
        rep(j, N) {
            cin >> grid[i][j];
            appear[grid[i][j]]++;
        }
    }
    vec<int> freq(2 * N + 1);
    vec<arr<int, 2>> has(N + 2, {0, 0});
    arr<int, 2> place{0, 0};  //where shall 2 be?
    rep(i, 2, 2 * N + 1) {
        if (i - 1 <= N) { freq[i] = i - 1; }
        else { freq[i] = 2 * N - i + 1; }
        has[freq[i]][bool(has[freq[i]][0])] = i;
        if (appear[i] == 1) {
            place[bool(place[0])] = i;
        }
    }
    auto check = [&](int col) {
        int r, c;
        rep(i, N) {
            rep(j, N) {
                if (grid[i][j] == col) {
                    r = i, c = j;
                }
            }
        }
        vec<int> mp(2 * N + 1); //which is it mapped to
        rep(i, N) {
            rep(j, N) {
                if (i == r || j == c) {
                    mp[grid[i][j]] = has[appear[grid[i][j]]][0];
                }
            }
        }
        rep(i, 2, 2 * N + 1) {
            if (mp[i]) { continue; }
            mp[i] = has[appear[i]][1];
        }
        vec<vec<int>> fin(N, vec<int>(N));
        rep(i, N) {
            rep(j, N) {
                fin[i][j] = mp[grid[i][j]];
            }
        }
        return fin;
    };
    vec<vec<int>> fin1 = check(place[0]);
    
    vec<vec<int>> fin2 = check(place[1]);
    vec<vec<int>> fin;
    bool done = false;
    rep(i, N) {
        rep(j, N) {
            if (fin1[i][j] != fin2[i][j]) {
                if (fin1[i][j] < fin2[i][j]) {
                    fin = fin1;
                    done = true;
                    break;
                }   else {
                    fin = fin2;
                    done = true;
                    break;
                }
            }
        }
        if (done) { break; }
    }
    rep(i, N) {
        rep(j, N) {
            cout << fin[i][j] << " \n"[j == N - 1];
        }
    }

}