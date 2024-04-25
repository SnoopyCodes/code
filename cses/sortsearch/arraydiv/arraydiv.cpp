#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> sums;
vector<int> v;
int N, K;
int valid(ll g) {
    ll cur = 0;
    int sects = 1;
    for (int i = 0; i < N; i++) {
        if (cur + v[i] > g) {
            sects++; cur = v[i];
            if (cur > g) { return 0; }
        }   else {
            cur += v[i];
        }
    }
    if (sects > K) { return 0; }
    if (sects < K) { return -1; }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> K;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    //we cannot just binary search
    //can we?
    //if we run a binary search is it guaranteed to give optimal results?
    //the trouble is that this might be ternary or smth
    //uhhhhhhhhh lets see
    //wait why tf does this lamost work someone help
    //
    ll s = 0, e = 2e14 / K;  //surely this works
    while (s + 1 < e) {
        ll m = (s + e) / 2;
        int v = valid(m);
        if (v == 1 || v == -1) { e = m; }
        else { s = m; }
        //so done with this
    }
    cout << e << "\n";
}