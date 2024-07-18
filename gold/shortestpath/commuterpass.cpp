#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Station {
    vector<array<int, 2>> roads;
    
};
vector<Station> stations;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n, m; cin >> n >> m;
    stations.resize(n);
    int s, t; cin >> s >> t;
    int u, v; cin >> u >> v;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c; a--; b--;

    }
    //bro
    //why is this so hard
    //good lord ok so
    //find all shortest path routes
    //brute force it
    //bro how many shortest path routes can there be
    //greedy doesn't work
    //ok the problem is we probably want to maintain the shortest path
    //idea
    //however i think this is done by like :dead:
    //help?
    //ummmmmmm ok so
    //we can regard it as building new edges with cost 0?
    //uhm
    //wait...
    //you won't ever go onto a certain path and then leave and
    //COME BACK
    //THEREFORE
    //THE GREEDY WORKS
    //so first we find all sp routes from s to t
}