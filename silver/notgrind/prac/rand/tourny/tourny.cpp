#include <bits/stdc++.h>
#define ll long long

using namespace std;
struct opp {
    int wins, prep;
};
vector<opp> opps;
bool comp(opp o1, opp o2) {
    return o1.prep < o2.prep;
}
bool compwins(opp o1, opp o2) {
    return o1.wins > o2.wins;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) { 
        int n, m; cin >> n >> m;
        opps.resize(n);
        for (int i = 0; i < n; i++) {
            opps[i].wins = i;
            cin >> opps[i].prep;
        }
        //we can binary search for the number of wins we want
        //yea probably just sort by prep time and go for that
        sort(opps.begin(), opps.end(), comp);
        //do we just walk through the array and then sort by wins?
        //wait also when we sort by the ones which we wish to face we should want to face the later ones
        int prepped = 0, win = 0;
        while (prepped <= m && win < n) {
            //if the one 2 in front is 2 more than us overtake that one first?
            //does this only apply if we have like only enough for 1?
            //
            //figure out if its the last one
            // if (win < n - 1 && prepped + opps[win].prep + opps[win+1].prep > m) {
            //     int a = win+1;
            //     while (a < n && prepped + opps[a].prep <= m) {
            //         if (opps[a].wins == 1 + win && prepped + opps[a].prep <= m) {  //if this next one has one more win than us, switch it bc we can beat it?
            //             opp tmp = opps[a];
            //             opps[a] = opps[win];
            //             opps[win] = tmp;
            //             break;
            //         }
            //         a++;
            //     }
            // }
            prepped += opps[win].prep; win++;
        }
        if (prepped > m) { win--; }
        int tmp = win;
        while (tmp < n) {
            opps[tmp].wins++; tmp++;
        }
        //is it an edge case?
        //do we only need to check 2 forward to see if we can win the other
        //ignore 
        opps.push_back({win, -1});
        sort(opps.begin(), opps.end(), compwins);
        int diff = 0, prev = opps[0].wins;
        for (int i = 0; i < n+1; i++) {
            if (opps[i].wins != prev) { prev = opps[i].wins; diff++; }
            else {  }
            if (opps[i].prep == -1) { break; }
        }
        cout << ++diff << "\n";
    }
}