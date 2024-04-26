#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, X; cin >> N >> X;
    vector<int> v(N);
    vector<ll> pfx(N+1);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < N; i++) {
        pfx[i+1] = pfx[i] + v[i];
    }
    //does shifting stuff up help?
    //prefix sums?
    //ya run prefix sums and do that
    map<ll, int> sums;
    ll amt = 0;
    sums[0] = 1;
    for (int i = 0; i < N; i++) {
        //help
        if (sums.find(pfx[i+1] - X) != sums.end()) { amt += (*(sums.find(pfx[i+1] - X))).second;
 
        }
        sums[pfx[i+1]]++;
    }
    cout << amt << "\n";
}