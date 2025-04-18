#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<array<long, 2>> monsters(N);
    long total = 0;
    for (int i = 0; i < N; i++) {
        cin >> monsters[i][0] >> monsters[i][1];
        total += monsters[i][0];
    }
    //min bullets to kill all monsters..
    //we want to maximize the value of explosion damage done
    long worst = 1e18;
    for (int i = 0; i < N; i++) {
        monsters[i][1] = min(monsters[i][1], monsters[(i+1)%N][0]);
        worst = min(monsters[i][1], worst);
        total -= monsters[i][1];
    }
    cout << total + worst << "\n";
    //we have to choose to kill some monsters
    //anyways
    //turn it into non circle first
    //last one is not a good idea to kill
    //in fact it is always optimal to start killing from the leftmost
    //we can actually activate the explosion damage of all except one
    //therefore just choose the one with minimum explosion damage

}