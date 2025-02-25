#include <bits/stdc++.h>

#define vec vector
#define arr array
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rep(...) GET_MACRO(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define rep3(x,s,e) for(auto x=s;x!=e;s<e?x++:x--)
#define rep2(x,e) rep3(x,(e>0?0:-(e)-1),(e>0?e:-1))
#define long int64_t

using namespace std;

vec<vec<int>> radj;
vec<int> F, C;
arr<long, 2> dfs(int u) {
    arr<long, 2> res {C[u], 0};
    for (int v : radj[u]) {
        auto x = dfs(v);
        //if we take this one, we can choose whether to take or not?
        res[0] += min(x[1], x[0]);
        //if we don't take this one, we have to take this one
        res[1] += x[0];
    }
    return res;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    F.resize(N), C.resize(N), radj.resize(N);
    vec<bool> visited(N);
    rep(i, N) {
        cin >> F[i];
        F[i]--;
    }
    rep(i, N) {
        cin >> C[i];
        if (F[i] == i) {
            visited[i] = true;
            C[i] = 0;
        }
    }

    long ans = 0;
    vec<bool> in_path(N);
    rep(i, N) {
        if (visited[i]) { continue; }
        int u = i;
        stack<int> path;
        while (!visited[u]) {
            in_path[u] = true;
            visited[u] = true;
            path.push(u);
            u = F[u];
        }
        if (in_path[u]) {
            int least = u;
            while (in_path[u]) {
                int v = path.top(); path.pop();
                in_path[v] = false;
                if (C[v] < C[least]) {
                    least = v;
                }
            }
            ans += C[least];
            C[least] = 0;
            F[least] = least;
        }
        while (!path.empty()) {
            int v = path.top(); path.pop();
            in_path[v] = false;
        }
    }
    rep(i, N) {
        if (F[i] != i) { radj[F[i]].push_back(i); }
    }
    rep(i, N) {
        if (F[i] == i) {
            auto res = dfs(i);
            ans += min(res[0], res[1]);
        }
    }
    cout << ans << "\n";
    //how did i miss 13?
    //everything is a line
    //its a gosh dang line man
    //or its a loop
    //...
    //what do we do if its a loop
    //isnt this cycle decomp weird thing

}