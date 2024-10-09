#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, K; cin >> N >> K;
    vector<int> v(N);
    vector<int> freq(101);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        freq[v[i]]++;
    }
    //it is always optimal to exchange for what we have right now
    //so we should always try and change things to the largest value?
    bool val = false;
    for (int i = 0; i < 101; i++) {
        if (freq[i] >= K) { val = true; break; }
    }
    if (val) {
        cout << K-1 << "\n";
    }   else {
        cout << N << "\n";
    }
    //wtf?
    //but what is it in the end
    //like we dont care baout simulation
    //make a frequency table
    //and then sort in reverse
    //surely this is too complicated
    //wtf help
    //obviously minimum it gets to is k-1
    //but then what
    //1 1 1 1 2 2 3
    //anything with 1 keeps dropping it
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}