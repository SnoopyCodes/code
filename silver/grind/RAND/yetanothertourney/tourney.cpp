#include <bits/stdc++.h>

using namespace std;
void solve() {
    //sort opps by prep time to win; if same prep sort by most wins
    //each we know has a certain amt of wins
    //so 1. we must always have the most amt of wins possible
    //then we can consider redistributing it ex what if we win against this guy
    //we should count win frequency ie 2 people have 4 wins (including over you) so arr[4] = 2
    //wait so we need to consider only 2 people if they have same amt of wins
    //can we only win if we beat the person in front by 1?
    //it gives 2 instead of 3?
    //
    int N, M; cin >> N >> M;
    vector<pair<int, int>> opps(N);
    for (int i = 0; i < N; i++) {
        cin >> opps[i].first;
        opps[i].second = i+1;
    }
    sort(opps.begin(), opps.end());
    int opp = 0;
    while (opp < N && M >= opps[opp].first) {
        M -= opps[opp].first;
        opp++;
    }
    opp--;
    int wins = opp+1;
    int max_cost = M + (wins > 0 ? opps[opp].first : 0);
    opp = 0;
    while (opp < N && max_cost >= opps[opp].first) {
        if (opps[opp].second == wins+1) {
            wins++; break;
        }
        opp++;
    } 
    cout << N+1 - wins << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}