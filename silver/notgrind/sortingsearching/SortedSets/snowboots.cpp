#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //freopen("snowboots.in", "r", stdin);
    //freopen("snowboots.out", "w", stdout);
    int N, B; cin >> N >> B;
    vector<int> tiles(N);
    vector<bool> makeable(N);
    for (int i = 0; i < N; i++) {
        cin >> tiles[i];
    }
    vector<array<int, 3>> boots(B);
    for (int i = 0; i < B; i++) {
        cin >> boots[i][0] >> boots[i][1];
        boots[i][2] = i;
    }
    sort(boots.begin(), boots.end());
    vector<array<int, 2>> jumps(N);
    //we can't just toss everything forwards
    //we should sort boots by depth
    //once we do that we must then tell what 
    //wait we absolutely must iterate over every tile i think?
    //how do we not?
    //definitely iterate over all tiles
    //good
    //then
    for (int i = 0; i < B; i++) {
        cout << boots[i][0] << "_" << boots[i][1] << "_" << boots[i][2] << " ";
    }
    cout << "\n";
    //okay we can now use an ordered map saying boots from 
    //[i ... N) are allowed on this one, at this time
    //we are transitioning tiles to time
    //we must also mark the longest time jump
    //for each
    //afterwards we move through each of the boots and see if 
    //their longest time jump is ok
    map<int, int> allowed;
    allowed[0] = 0;
    for (int i = 1; i < N; i++) {
        //bs
        int s = -1, e = B;
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if (boots[m][0] < tiles[i]) { s = m; }
            else { e = m; }

        }
        s = e;
        if (boots[s][0] < tiles[i]) { continue; }
        //boots from [s, N) can step on this
        //find the last time boots with at least depth s stepped here
        //find the first >= this one
        int x = (*(--allowed.upper_bound(boots[s][0]))).second;
        jumps[s] = max(jumps[s], {i - x, i});
        allowed[s] = i;
        //this marks that there is a jump of i - previ
        for (auto it = ++allowed.find(s); it != allowed.end(); it++) {
            int p = (*it).first, v = (*it).second;
            jumps[p] = max(jumps[p],{i - v, i});
        }
        allowed.erase(++allowed.find(s), allowed.end());
        //erase to the right bc this is the latest best
        //but before we need to record time jumps
        //what if we consider by boots?
        //it should be much simpler to query for
        //the furthest dist between any 2 of the allowed tiles
        //
    }

    int jump = INT_MAX, time = 0;
    for (int i = 0; i < B; i++) {
        if (jumps[i][0] != 0 && jumps[i][1] > time) { jump = min(jumps[i][0], jump); time = jumps[i][1]; }
        makeable[boots[i][2]] = (boots[i][1] >= time);
        cout << jumps[i][0] << " ";
    }
    cout << "\n";
    for (int i = 0; i < B; i++) {
        cout << makeable[i] << " ";
    }
}