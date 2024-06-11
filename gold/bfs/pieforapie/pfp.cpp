#include <bits/stdc++.h>

using namespace std;
struct Pie {
    int bv, ev;
};
bool compb(Pie p1, Pie p2) {
    return p1.bv < p2.bv;
}
bool compe(Pie p1, Pie p2) {
    return p1.ev < p2.ev;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //freopen("piepie.in", "r", stdin);
    //freopen("piepie.out", "w", stdout);
    int N, D; cin >> N >> D;
    vector<Pie> bess(N);
    vector<Pie> queen(N);
    for (int i = 0; i < N; i++) {
        cin >> bess[i].bv >> bess[i].ev;
    }
    sort(bess.begin(), bess.end(), compb);
    for (int i = 0; i < N; i++) {
        cin >> queen[i].bv >> queen[i].ev;
    }
    sort(queen.begin(), queen.end(), compe);
    //what? aint this evil?
    //this is incredibly difficult wtf
    //so uh
    //maybe we can bfs from the values for which a 0 is had
    //so that we can cover everything
    //how many times are we allowed to visit something?
    //if a 0 is had, we should bfs and trace back
    bool b = true;
    bool e = false;
    vector<int> bdists(N, INT_MAX);
    vector<int> qdists(N, INT_MAX);
    queue<array<int, 2>> q;
    //we definitely have the right idea tho
    for (int i = 0; bess[i].ev == 0 && i < N; i++) {
        q.push({i, b});  //we are receiving something we think is worth this much
        bdists[i] = 1;
    }
    for (int i = 0; queen[i].bv == 0 && i < N; i++) {
        q.push({i, e});
        qdists[i] = 1;
    }
    //if we run a multisource such as this is it really okay
    //probably?
    //can we just throw in those nodes?
    while (!q.empty()) {
        int v = q.front()[0];
        if (q.front()[1]) {  //bessie is gifting something of value q.front()[0]
            //if we are giving something of this value, then we received something in v - K
            //binary search on the first value >= to v - K
            //then we iterate through this 
            //there might be some thought that are repeated
            //eh we'll get there later
            int s = -1, e = v;
            while (s + 1 < e) {
                int m = (s + e) / 2;
                if (bess[m].bv >= bess[v].bv - D) {
                    e = m;
                }   else {
                    s = m;
                }
            }
            while (e < v) {
                
            }
        }   else {
            
        }
    }
}