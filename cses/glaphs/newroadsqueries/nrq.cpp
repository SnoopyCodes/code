#include <bits/stdc++.h>

using namespace std;
vector<int> dsu;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //we may utilize dsu on this for sure
    //but are we really to add queries to each cc
    //and then check each cc?
    //we can instead mark for each querie which cc it belongs to, then binary search on the first day 
    //for which they are the same?
    //naive approach is a scary O(MQ alpha(M)) where we check every day every query
    //storing for node where it goes...
    //this is the same as dragging it along isnt it?
    //honestly i bet this passes anyways like it should not but it probably will
    //actually i dont believe it
    //lmao
    //maybe this is too hard ill do it later
    int N, M, Q; cin >> N >> M >> Q;
    vector<array<int, 2>> edges(M);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--; b--;
        edges[i] = {a, b};
    }
    for (int i = 0; i < N; i++) {
        dsu[i] = i;
    }
    //we could very well build a difference away, but why wud we do that
    //we now need to store for each city we are querying the city
}