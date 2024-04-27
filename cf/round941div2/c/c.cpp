#include <bits/stdc++.h>

using namespace std;
vector<int> v;
void solve() {
    int N; cin >> N;
    set<int> s;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    //help how to do
    //what is optimal?
    //so the last one always ignored
    //whoever has turn on last wins
    //wait it is bound by max of last val
    //is there a greedy strategy available to the players
    //the goal is to force the other player to have to attack
    //the next one - 1
    //is this dp
    //so at that point if there is another pile
    //the player that gets to that one first wins, unless only 1 left
    //but from there
    //its the same thing all the way down
    //force opp to choose 1, then you get priority on the next one
    //if the piles are split, though
    //only the ones where the diff > 1 matters
    //is it the first transmission that matters
    //i think its count the chain of transmission
    //bob should just wn in this case but why is it giving me the wrong count
    N = s.size();
    v.clear();
    for (auto x : s) {
        v.push_back(x);
    }
    bool init = true;  //true is alice, false is bob
    int remove = 0;
    int i = 0;
    while (i < N - 1 && v[i] - remove == 1) {
        init = !init;
        remove = v[i];
        i++;
    }
    if (init) { cout << "Alice" << "\n"; }
    else { cout << "Bob" << "\n"; }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}