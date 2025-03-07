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

    /*
    suppose that we actually do have something existing
    a, b
    now every other node needs to connect to a or b
    so combine a and b together, call it X
    suppose X connects to c as it must
    b-c
    "a" no longer needs to
    wait is htis like a tree thing ??
    are there some nodes for which every single other node connects all of them??
    consider a-b-c-d as central nodes then, doesn't "a" need to connect to "d"?
    is there any node that goes to all of them?
    star graph, least edges i mean...
    */
   //why does the indent after a comment start here, any erxplanations?
   //editorial: 
    int N, M; cin >> N >> M;
    vec<vec<bool>> reach(N, vec<bool>(N));
    rep(i, M) {
        int u, v; cin >> u >> v; u--; v--;
        reach[u][v] = true;
        reach[v][u] = true;
    }
    

}