#include <bits/stdc++.h>

using namespace std;

#define int long long
#define add push_back
const int MOD = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;
const auto &rn = views::iota;
vt<vt<int>> T;
vt<int> lei, gao;
vt<int> in, out;
int ans = 0;
/*
for (int i = a; i < b; i++)
for (int i : rn(a, b)) -> saves 5, worth after 6
rep (i, a, b) -> saves 9, 14, worht after 4
*/
int dfs(int u, int p) { //change return
    int pairs = min(in[u], out[u]);
    ans -= lei[u] * pairs;
    int diff = max(in[u], out[u]) - pairs;

    vt<int> saves;
    for (int v : T[u]) {
        if (v == p) { continue; }
        int x = dfs(v, u) ;
        if (~x) {
            //this is an equal. 
            /*
            the function goes as follows: for the first diff equal edges, 
                we save lei[u].
                afterwards, we save lei[u] / 2.
                finally, if we have one left over, that one saves 0.
                and, each one of these has a cost associated with them- how much we pay back
                if we use them here.
                obviously, we want max save against minimum pay back, first. sort the children
                and we finally consider the "equal" u to p edge, if it exists.
                if it can't match with anything, then costs 0.

                wait it is like an equal edge with payback 0, but we want to minimize the payback
                we put into it. therefore we use it last.

                i feel there is an edge case in the function cost change.
            */
           saves.add(x);
        }
    }

    ranges::sort(saves);
    ranges::reverse(saves); //least cost to change first.
    while (size(saves)) {
        int x = saves.back(); saves.pop_back();
        
        if (diff) {
            if (x < lei[u]) {
                ans += x;
                ans -= lei[u];
                diff--;
            }   else {
                break;
            }
        }   else {
            if (size(saves)) {
                int y = saves.back(); saves.pop_back();
                if (x + y < lei[u]) {
                    ans += x + y;
                    ans -= lei[u];
                }   else {
                    saves.add(y);
                    saves.add(x);
                    break;
                }
            }   else {
                saves.add(x);
                break;
            }
        }
    }
    if (~p && gao[u] == gao[p]) {
        //select an edge to whatever.
        if (diff) {
            ans -= lei[u];
            return lei[u];
        }   else {
            if (size(saves)) {
                int x = saves.back();
                if (x < lei[u]) {
                    ans -= lei[u];
                    ans += x;
                    return lei[u] - x;
                }   else {
                    return 0;
                }
            }   else {
                return 0;
            }
        }
    }   else {
        return -1;
    }

    
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    T.resize(N), lei.resize(N), gao.resize(N), in.resize(N), out.resize(N);
    for (int i : rn(N)) cin >> lei[i];
    for (int i : rn(N)) cin >> gao[i];
    for (int i : rn(N - 1)) {
        int u,v; cin >> u >> v; u--; v--;
        T[u].add(v);
        T[v].add(u);
        ans += lei[u] + lei[v];
        if (gao[u] < gao[v]) {
            in[u]++, out[v]++;
        }   else if (gao[v] > gao[u]) {
            out[u]++, in[v]++;
        }
    }
    cout << ans << "\n";
    dfs(0, -1);
    cout << ans << "\n";
}