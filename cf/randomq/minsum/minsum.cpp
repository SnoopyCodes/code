#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> v;
void solve() {
    int N, K; cin >> N >> K;
    v.resize(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        sum += v[i];
    }
    for (int k = 0; k < K; k++) {
        int mi = 0;
        int mj = 0;
        for (int i = 1; i < N - 1; i++) {
            if (v[mi+1] - v[mi] < v[i+1] - v[i]) {
                mi = i;
            }
            if (v[mj+1] - v[mj] > v[i+1] - v[i]) {
                mj = i;
            }
        }
        //oh it doesnt consider the ones 10 next over..
        //we should just create a difference array tbh
        //segtree :skull:
        if (N > 1) {
            if (v[mi+1] - v[mi] > -(v[mj+1] - v[mj])) {
                sum -= (v[mi+1] - v[mi]);
                v[mi+1] = v[mi];
            }   else {
                sum += v[mj+1] - v[mj];
                v[mj] = v[mj+1];
            }
        }
    }
    cout << sum << "\n";
    //so clearly we consider the difference between one and the next
    //we should be able to find the amount that using one element helps
    //going forwards and backwards
    //wait k 0 to 10
    //lmao just greedy?
    //i pray
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}