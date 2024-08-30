#include <bits/stdc++.h>

using namespace std;
struct Pie {
    int bv, ev;
};

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
    for (int i = 0; i < N; i++) {
        cin >> queen[i].bv >> queen[i].ev;
    }
    bool b = true;
    bool e = false;
    vector<int> bdists(N, -1);
    vector<int> qdists(N, -1);
    queue<array<int, 2>> q;
    multiset<array<int, 2>> unvis_b;
    multiset<array<int, 2>> unvis_e;
    for (int i = 0; i < N; i++) {
        if (bess[i].ev != 0) { unvis_b.insert({bess[i].bv, i}); continue; }
        q.push({i, e});  //elsie is receiving this pie she thinks is worth 0, bessie sends
        bdists[i] = 1;
    }
    //visible confusion??
    //how does that 
    
    for (int i = 0; i < N; i++) {
        if (queen[i].bv != 0) { unvis_e.insert({queen[i].ev, i});continue; }
        q.push({i, b});  //elsie is sending this pie
        qdists[i] = 1;
    }
    cout << "\n";
    while (!q.empty()) {
        int pie = q.front()[0];
        int from = q.front()[1];
        q.pop();
        if (from == b) {
            int val = bess[pie].ev;
            auto beg = unvis_e.lower_bound({val - D, 0});
            auto stop = unvis_e.upper_bound({val + 1, -1});
            for (auto it = beg; it != stop; it++) {
                int index = (*it)[1];
                //we have now reached this index
                qdists[index] = bdists[from] + 1;
                q.push({index, e});
            }
            unvis_e.erase(beg, stop);
        }   else {
            int val = queen[pie].bv;
            auto beg = unvis_e.lower_bound({val - D, 0});
            auto stop = unvis_e.upper_bound({val + 1, -1});
            for (auto it = beg; it != stop; it++) {
                int index = (*it)[1];
                //we have now reached this index
                bdists[index] = qdists[from] + 1;
                q.push({index, b});
            }
            unvis_b.erase(beg, stop);
        }
    }
    for (int i = 0; i < N; i++) {
        cout << bdists[i] << "\n";
    }
}