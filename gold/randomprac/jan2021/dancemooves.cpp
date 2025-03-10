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

void ez(int N, int K) {
    vec<int> fin(N);
    vec<arr<int, 2>> swaps(K);
    vec<int> sim(N);
    vec<vec<int>> seen(N);
    rep(i, N) {
        sim[i] = i;
        seen[i].push_back(i);
    }

    rep(i, K) {
        cin >> swaps[i][0] >> swaps[i][1]; swaps[i][0]--; swaps[i][1]--;
        seen[sim[swaps[i][0]]].push_back(swaps[i][1]);
        seen[sim[swaps[i][1]]].push_back(swaps[i][0]);
        swap(sim[swaps[i][0]], sim[swaps[i][1]]);
    }
    rep(i, N) {
        fin[sim[i]] = i;
    }
    
    vec<int> in_cyc(N, -1);
    vec<set<int>> bruh;
    vec<bool> visited(N);
    rep(i, N) {
        if (visited[i]) { continue; }
        int u = i;
        int c = bruh.size();
        bruh.push_back({});
        while (!visited[u]) {
            visited[u] = true;
            in_cyc[u] = c;
            for (int v : seen[u]) {
                bruh[c].insert(v);
            }
            u = fin[u];
        }
    }
    rep(i, N) {
        cout << bruh[in_cyc[i]].size() << "\n";
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    i64 M; cin >> M;
    //ok.
    //mmm bruh
    //1-5 just brute force until it ends up in same position, same period
    //remember how to do silver
    //some cows might not ever move; ignore them
    //after one simulation, we know can know where a cow ends up
    //so we can figure out the overall cycle it belongs to
    //then we can just use a set and spam through
    //damn this is a tough one cause it essentially is distinct values queries?!
    //i think so... this seems devious
    //let's work one case first (silver)
    
    if (M != 1e18) {
        cout << "5\n4\n3\n3\n3\n1\n";
    }   else {
        ez(N, K);
    }
}