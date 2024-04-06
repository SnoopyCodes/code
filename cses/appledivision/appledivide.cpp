#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    vector<int> weights(N);
    ll total = 0;
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
        total += weights[i];
    }
    ll mindiff = INT_MAX;
    for (ll mask = 0; mask < pow(2, N); mask++) {
        ll sum = 0;
        for (int i = 0; i < N; i++) {
            sum += (mask & 1 << i) != 0 ? weights[i] : 0;
        }
        mindiff = min(mindiff, abs(total - sum - sum));
    }
    cout << mindiff << "\n";
    //now do good
    //wait actually just take a total sum and consider all the different sums
    //is there not a better way to do this
}