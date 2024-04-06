#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool comp(array<ll, 2> a1, array<ll, 2> a2) {
    return a1[1] < a2[1];
}
void solve() {
    ll N, M, K; cin >> N >> M >> K;
    vector<array<ll, 2>> costs(N);
    for (int i = 0; i < N; i++) {
        cin >> costs[i][0];
        costs[i][1] = i;
    }
    ll money = 0;
    ll plus = 0;
    ll total = 0;
    sort(costs.begin(), costs.end());
    vector<array<ll, 2>> best;
    for (int i = 0; i < K / M + (K % M != 0); i++) {
        best.push_back(costs[i]);
        total += costs[i][0];
    }
    sort(best.begin(), best.end(), comp);
    N = best.size();
    //how to ?
    //how how how how how?
    //i don't know if we can play off average
    //welp do we try it?
    //because otherwise i dunno
    //we have at each step just current cost, amount left to buy, amount we can buy
    //also stuff about the rest of hte array if we want though
    //we can get sum to end if we want
    //is it like still optimal to choose the lowest?
    //how do we basically increase the cost of our own day based on the number of tickets we buy?
    //what if we like win
    //the function is like x * a + (o-x) * x = (o - x + a) * x
    //for the actual cost of the thing
    //we can basically only control x. find a way to minimize (o - x + a) * x. minimize (c - x) * x
    //
    for (int i = 0; i < N; i++) {
        
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) {T--; solve(); }
}