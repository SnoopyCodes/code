#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
vector<int> cows;
vector<bool> change;
vector<pair<int, int>> mem;
bool comp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) { return p1.first < p2.first; }
    return p1.second < p2.second;
}
void solve() {
    int N, Q, C; cin >> N >> Q >> C;
    change.clear(); cows.clear(); mem.clear();
    change.resize(N);
    cows.resize(N);
    mem.resize(Q);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
        if (cows[i] == 0) { change[i] = true; cows[i] = 1;}
    }
    for (int i = 0; i < Q; i++) {
        cin >> mem[i].f >> mem[i].s;
        mem[i].f--; mem[i].s--;
    }
    //sort the mem by hj
    sort(mem.begin(), mem.end(), comp);
    //how to get max of 0 to a?
    //the values in 0 to a can change multiple times
    //there are just constraints on them
    //write up partials first
    //optimize the searches by using prefix maxes somehow
    //
    for (int i = 0; i < Q; i++) {
        //find max of 0 to a and a to h
        //and last to set
        int l0 = -1;
        int m1 = 0; 
        for (int j = 0; j <= mem[i].f; j++) {
            m1 = max(m1, cows[j]);
            if (change[j]) { l0 = j; }
        }
        int m2 = 0;
        for (int j = mem[i].f+1; j < mem[i].s; j++) {
            m2 = max(m2, cows[j]);
        }
        if (m2 > m1) {
            if (l0 == -1) { cout << -1 << "\n"; return; }
            cows[l0] = m2;
            m1 = m2;
        }
        //now check for h
        if (change[mem[i].s] && cows[mem[i].s] <= m1) { cows[mem[i].s] = m1+1; if (m1+1 > C) { cout << -1 << "\n"; return; }}
        else if (!change[mem[i].s] && cows[mem[i].s] <= m1) { cout << -1 << "\n"; return; }
    }
    //we can make a prefix max array to check that conditions hold
    vector<int> pfx(N);
    for (int i = 0; i < N; i++) {  //we need to check that all conditions hold
        if (i != 0) { pfx[i] = max(cows[i], pfx[i-1]); }
        else { pfx[i] = cows[i]; }
    }
    for (int i = 0; i < Q; i++) {
        if (pfx[mem[i].s-1] > pfx[mem[i].f] || pfx[mem[i].s] <= pfx[mem[i].f]) { cout << -1 << "\n"; return; }
    }
    for (int i = 0; i < N-1; i++) {
        cout << cows[i] << " ";
    }
    cout << cows[N-1];
    cout << "\n";
    //so the Q tells us that 
    //from 0 to ai we have the maximum in the range 0 to hj-1
    //thats it
    //so if we have a range 0 to ai with unknowns
    //i think we just greedy from 0
    //sort the Q's by h indexes
    //once we determine the numbers in a certain h
    //we can just turn all other 0's into 1 i think
    //yes
    //okay that sounds good
    //but how do we determine numbers
    //lets just first look at our 2 subarrays
    //find the maximum in the first and hte max in the second
    //if the maximum in the first is greater than max in second then we give up because invalid
    //when is it safe to determine everything in the array?
    //we should not set every 0 to 1 in the second array
    //or the first; rather just set all 0's to 1's in the end and then just do stuff
    //when do we have to change soemthing in the second subarray? do we ever?
    //idts
    //lets begin
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int T; cin >> T;
    while (T) {
        T--;
        solve();
    }
}