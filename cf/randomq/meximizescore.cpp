#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 998244353;

ll exp(ll x, int p) {
    ll res = 1;
    while (p > 0) {
        if (p & 1) { res = res * x % MOD; }
        x = x * x % MOD;
        p /= 2;
    }
    return res;
}

void solve() {
    int N; cin >> N;
    vector<int> A(N);
    vector<int> freq(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        freq[A[i]]++;
    }

    //consider the ones with MEX up to i, and the ones without that

    ll nomex = 0, mex = 0;
    int lim = N;
    for (int i = 0; i < N; i++) {
        //for every single subset without maxmex,
        //we can multiply by like 2^freq[i] bc there can be that many subsets without this
        nomex = nomex * exp(2, freq[i]) % MOD;
        //for the ones with maxmex, i have no idea
        //and then now
        //first, nomex += mex, because that many will not have any mex of our own
        nomex = (mex + nomex) % MOD;
        //now these subsets..?
        //we can add this many to them
        //what mex is saying is that the sum of scores of stuff with mex i is mex
        
        //and we also have lim!
        //
        
    }
    cout << (nomex + mex) % MOD;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}