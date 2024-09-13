#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<ll> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    //holy crap
    //smallest n - 1
    //well the smallest is like least and least + 1
    //lmfao so its just least
    //wait no
    ll ans = 0;
    const int MOD = 1e9 + 7;
    for (int sz = N; sz > 0; sz--) {
        vector<ll> res(sz - 1);
        vector<int> idx(sz);
        priority_queue<array<ll, 2>> pq;
        for (int i = 0; i < sz - 1; i++) {
            idx[i] = i+1;
            pq.push({-(v[i] + v[i+1]), i});
        }
        for (int i = 0; i < sz - 1; i++) {
            res[i] = -pq.top()[0];
            int j = pq.top()[1];
            pq.pop();
            idx[j]++;
            if (idx[j] < sz) {
                pq.push({-(v[j] + v[idx[j]]), j});
            }
        }
        v = res;
        //HELP WHAT IS HAPPENING
        ll rem = v[0] / MOD;
        for (int i = 0; i < sz - 1; i++) {
            v[i] -= rem * MOD;
        }
    }
    cout << v[0] << "\n";
}