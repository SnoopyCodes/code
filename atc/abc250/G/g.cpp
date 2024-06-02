#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //this is an obvious dp problem
    int N; cin >> N;
    vector<int> days(N);
    for (int i = 0; i < N; i++) {
        cin >> days[i];
    }
    //obvious: each state has profit, and stonks
    //how to transition from days to the next one?
    //help days
    //this is easy in N^2 i think
    vector<ll> profits(N+1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j > 1) {  //sell
                
            }
        }
    }
}