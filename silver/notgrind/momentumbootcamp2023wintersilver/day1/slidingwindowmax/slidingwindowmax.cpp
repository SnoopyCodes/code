#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9+7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int N, K; cin >> N >> K;
    vector<int> v(N);
    ll total;
    for (int i = 0; i < N; i++) { cin >> v[i]; }
    //just take a set of the current subarray and then repeatedly remove and add stuff from it
    set<int> subarray;
    for (int i = 0; i < K; i++) {
        subarray.insert(v[i]);
    }
    total += *subarray.rbegin();
    for (int i = 0; i < N - K; i++) {  //remove index i and add index i+K
        subarray.erase(v[i]);
        subarray.insert(v[i+K]);
        total += *subarray.rbegin();
        total %= MOD;
    }
    cout << total << "\n";

}