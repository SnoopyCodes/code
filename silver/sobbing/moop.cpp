#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("moop.in", "r", stdin);
    freopen("moop.out", "w", stdout);
    //huh?
    //first lets sort by x
    //oh shit we can draw edges
    //or look for cc
    //so form connected components essentially
    //we can definitely do subtask 1 but how speed?
    //sort both ways
    int N; cin >> N;
    vector<array<int, 3>> P(N);
    set<array<int, 3>> s;
    for (int i = 0; i < N; i++) {
        cin >> P[i][0] >> P[i][1];
        P[i][2] = i;
        s.insert({P[i][1], P[i][0], i});
    }
    //we can use a set to speed it up i think
    //yea definitely im pretty sure
    //wait i am not cooking
    //hold on i can do this i think
    //when can we not reach another thing?
    //if one dimension is greater and one dimension is less
    //wait i think i have brain damage
    vector<bool> vis(N);
    int cc = 0;
    sort(P.begin(), P.end());
    for (int i = 0; i < N; i++) {
        bool valid = true;
        for (auto it = s.find({P[i][1], P[i][0], P[i][2]}); it != s.end(); it++) {
            auto const&[y, x, idx] = *it;
            if (vis[idx]) { valid = false; break; }
            else { vis[idx] = true; }
        }
        cc += valid;
        s.erase({P[i][1], P[i][0], P[i][2]});
    }
    cout << cc << "\n";
}