#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Action {
    int x, y, t;
};
bool sortt(Action a1, Action a2) {
    return a1.t < a2.t;
}
vector<Action> alibis;
vector<Action> grazings;
ll dist(int x1, int y1, int x2, int y2) {
    return (ll) (x2 - x1) * (x2 - x1) + (ll)(y2 - y1) * (y2 - y1);
}
bool reaches(Action a1, Action a2) {
    return (ll) dist(a1.x, a1.y, a2.x, a2.y) <= (ll) (a2.t - a1.t) * (a2.t - a1.t);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("in.txt", "r", stdin);
    int G, N; cin >> G >> N;
    alibis.resize(N);
    grazings.resize(G);
    for (int i = 0; i < G; i++) {
        cin >> grazings[i].x >> grazings[i].y >> grazings[i].t;
    }
    for (int i = 0; i < N; i++) {
        cin >> alibis[i].x >> alibis[i].y >> alibis[i].t;
    }
    sort(grazings.begin(), grazings.end(), sortt);
    sort(alibis.begin(), alibis.end(), sortt);
    int last = 0;
    int innocents = 0;
    for (int i = 0; i < G; i++) {
        while (last != N && alibis[last].t <= grazings[i].t) {
            if (i != 0) {
                if (!reaches(alibis[last], grazings[i-1])) {
                    innocents++; last++; continue;
                }
            }
            if (!reaches(alibis[last], grazings[i])) {
                innocents++;
            }
            last++;
        }
        if (last == N) { break; }
    }
    while (last != N) {
        if (!reaches(alibis[last], grazings[G-1])) {
            innocents++;
        }
        last++;
    }
    cout << innocents;
    
}