#include <bits/stdc++.h>
#define ll long long
#define bf badfriend
using namespace std;
struct badfriend {
    ll cookie, muffin, temper;
};
vector<bf> bfs;
ll tc, tm;
bool works(int u) {
    int minc = INT_MAX, minm = INT_MAX; //maximum required cookie upgrades, max required muffin upgrades
    int maxc = 0, maxm = 0;
    int c = tc, m = tm;
    //there are 4 vals:
    //min c up, max c up, min m up, max m up;
    //min c up goes iwth max m up for saying: for at least one friend, they require this many upgrades on c, and for at least one friend, they require this many
    //upgrades on m.
    for (int i = 0; i < bfs.size(); i++) {
        int dc = c, dm = m;
        ll temper = bfs[i].temper;
        //my temper ran out goodbye
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        ll N;
        cin >> N >> tc >> tm;
        bfs.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> bfs[i].cookie >> bfs[i].muffin >> bfs[i].temper;
        }
        //ok so find the largest time constraints?
        //or check how much difference itll make
        //binary search for the amount of times we upgrade the cookie, and then the muffin
        //what if we binary search for the amount of upgrades?
        //can we figure out from there?
        //i think so actually? wait what now
        int l = 0, r = tc+tm-1;
        while (r - 1 >= l) {
            int m = (r+l-1) / 2;
            if (works(m)) { r = m+1; }  //want to find the min
            else { l = m+1; }
        }
        cout << l << "\n";
    }
}