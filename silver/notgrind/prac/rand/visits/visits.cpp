#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<pair<int, int>>> buddies;
vector<bool> visited;
struct Cow {
    int i, f; ll fval;  //index i, friend, friendship val
};
vector<Cow> cows;
bool comp(Cow c1, Cow c2) {
    return c1.fval < c2.fval;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    buddies.resize(N);
    cows.resize(N);
    visited.resize(N);
    ll total;
    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b; a--; b;
        cows[i].f = a;
        buddies[a].push_back({a, b});
        cows[a].fval += b;
        //weighted graph
        //you can then apply a "total friendship value" to each cow
        //the problem is where do we decide to allow cows to go or not to go
        //start with cows that "give" more or the same friendship value than they receive
        //is this guaranteed i think so
        //so cows that have the least friendship val should send i think
        //priority by just least? if its 0 then obv send
        //but also if its like not completely connected then everything can be sent
        //in cycles we can choose 1 thing not to be sent?
    }
}