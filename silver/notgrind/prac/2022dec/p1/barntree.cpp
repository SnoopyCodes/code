#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> barns;
vector<vector<int>> roads;
vector<bool> visited;
struct Instruct {
    int f, t, v;  //from, to, value
};
vector<Instruct> instructions;
int target;
int check(int i) {
    if (visited[i]) { return 0; }
    visited[i] = true;
    int help = target - barns[i];  //how mcuh we need to send
    //for each barn, we should send supplies to them before they send
    vector<Instruct> neg;
    for (int x : roads[i]) {
        int send = check(x);
        help += send;
        if (send < 0) {
            neg.push_back({x+1, i+1, -send});
        }  else if (send > 0) {
            instructions.push_back({i+1, x+1, send});
        }
    }
    for (Instruct j : neg) { instructions.push_back(j); }
    return help;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //tree problem
    //should we take the orders the furthest away?
    freopen("in.txt", "r", stdin);
    int N; cin >> N;
    barns.resize(N);
    visited.resize(N);
    roads.resize(N);
    ll total = 0;
    int maxi=  0;
    for (int i = 0; i < N; i++) {
        cin >> barns[i];
        total += barns[i];
        if (barns[maxi] < barns[i]) { maxi = i; }
    }
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b; a--; b--;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    target = total / N;
    check(maxi);
    cout << instructions.size() << "\n";
    // for (Instruct i : instructions) {
    //     cout << i.f << " " << i.t << " " << i.v << "\n";
    // }
    //we can choose nodes with too many bales and work from there?
    //this problem... we can get 9/16 if we just partial...
    //choose a node randomly, and then from each of the branches
    //find how many each branch will eventually send back or something
    //bruh bfs??
    //if we use bfs we can track back paths and stuff
    //say we start from the one with the most
    //we can run a "check" on our branches to find 
    //how much each of the branches need
}