#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

int gmax(std::set<ints<2> > &s) { return (*s.rbegin())[0]; }
int gmin(std::set<ints<2>> &s) { return (*s.begin())[0]; }

void solve() {
    int N; std::cin >> N;
    vector<ints<2>> coord(N);
    vector<ints<2>> nn(N), np(N), pp(N), pn(N);
    for (int i = 0; i < N; i++) {
        std::cin >> coord[i][0] >> coord[i][1];
        auto [x, y] = coord[i];
        nn[i] = { -x-y, i };
        np[i] = { -x+y, i };
        pn[i] = { x-y, i };
        pp[i] = { x+y, i };
    }
    //wait we want to maximize?
    //make all coordinates + 1e6 to be nonnegative
    //its repeatedly remove miny, minx, maxy, maxx cause of the equation
    //if we just do like greedy
    //greedy is correct i think
    //i highly doubt this is segtree
    //messy thing
    //try not to do that
    //we have position
    //do we sort?
    //that's the whole problem?
    //we sort?
    //dude idk wtf like
    //
    std::sort(nn.begin(), nn.end());
    std::sort(np.begin(), np.end());
    std::sort(pn.begin(), pn.end());
    std::sort(pp.begin(), pp.end());
    vector<bool> done(N);
    int a, c, e; a = c = e = 0;
    int b, d, f; b = d = f = N - 1;
    for (int i = 0; i < N / 2; i++) {
        int x = pp[b][0] - pp[a][0];
        int y = pn[d][0] - np[c][0];
        int z = np[f][0] - pn[e][0];
        int u, v;
        if (x > y && x > z) {
            u = pp[b][1], v = nn[a][1];
        }   else if (y > z) {
            u = pn[d][1], v = np[c][1];
        }   else {
            u = np[f][1], v = pn[e][1];
        }
        std::cout << u+1 << " " << v+1 << "\n";
        done[u] = true, done[v] = true;
        if (i != N / 2 - 1)
        if (x > y && x > z) {
            while (done[b]) { b--; }
            while (done[a]) { a++; }
        }   else if (y > z) {
            while (done[d]) { d--; }
            while (done[c]) { c++; }
        }   else {
            while (done[f]) { f--; }
            while (done[e]) { e++; }
        }
    }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}