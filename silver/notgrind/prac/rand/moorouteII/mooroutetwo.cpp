#include <bits/stdc++.h>

using namespace std;
struct Flight {
    int t1, t2, dest; //leave time and arrival time, destination
    bool used = false;  //if we used this before
};
bool comp(Flight f1, Flight f2) {
    return f1.t1 < f2.t1;
}
vector<vector<Flight>> flights;
vector<int> layover;
vector<int> times;
int bs(int leave, int airport) {  //find the first flight that exits after leave
    if (flights[airport].size() == 0) { return -1; }
    int s = 0, e = flights[airport].size();
    while (e > s) {
        int m = (s + e) / 2;
        if (flights[airport][m].t1 >= leave) { e = m; }  //search go down
        else { s = m+1; }
    }
    if (flights[airport][e].t1 < leave) { return -1; }
    return e;
}
void dfs(int i, int t) {
    // cout << "arrived at" << " " << i << endl;
    if (t < times[i]) { times[i] = t; }
    else { return; }
    //find the first time where we can start from
    //we should not ever come back to i = 0
    //wait how do we figure out when to redo things
    //is there ever a need to use the same edge twice
    //no?
    int begin = bs(t + layover[i], i);
    // cout << t + layover[i] << " " << i << endl;
    if (i == 0) { begin = 0; }
    if (begin == -1) { return; }
    while (begin < flights[i].size()) {  //try the flights we can
        if (flights[i][begin].used) { break; }
        dfs(flights[i][begin].dest, flights[i][begin].t2);
        flights[i][begin].used = true;
        begin++;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    flights.resize(N);
    layover.resize(N);
    times.resize(N, INT_MAX);
    for (int i = 0; i < M; i++) {
        int f, t1, t, t2; // from time1 to time2
        cin >> f >> t1 >> t >> t2;
        f--; t--;
        Flight fly;
        fly.t1 = t1; fly.t2 = t2; fly.dest = t;
        flights[f].push_back(fly);
    }
    for (int i = 0; i < N; i++) {
        cin >> layover[i];
        sort(flights[i].begin(), flights[i].end(), comp);
        // cout << "flight"<< " " << i  << ": ";
        // for (Flight f : flights[i]) {
        //     cout  << f.t1 << " ";
        // }
        // cout << "\n";
    }
    //okay now start
    dfs(0, 0);
    for (int i = 0; i < N; i++) {
        if (times[i] == INT_MAX) { cout << -1 << "\n"; continue; }
        cout << times[i] << "\n";
    }
}