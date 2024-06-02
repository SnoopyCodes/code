#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, W; cin >> N >> W;
    //wait what
    //oh N <= 100 thank god i was like wtf
    vector<array<ll, 2>> items(N);
    for (int i = 0; i < N; i++) {
        cin >> items[i][0] >> items[i][1];
    }
    //so for each item consider taking it

    vector<ll> valOfWeights(W + 1);
    //so basically
    //we want to use valOfWeights to 
    for (int i = 0; i < N; i++) {
        for (int x = W; x >= 0; x--) {
            if (x + items[i][0] <= W) {
                valOfWeights[x + items[i][0]] = 
                max(valOfWeights[x + items[i][0]], valOfWeights[x] + items[i][1]);
            }
        }
    }
    ll mx = 0;
    for (ll sob : valOfWeights) {
        mx = max(mx, sob);
    }
    cout << mx << "\n";
}