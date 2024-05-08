#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N, K; cin >> N >> K;
    //start with 1, 2 ... until the next one we add is greater
    vector<int> v;
    int sum = 0;
    int it = 0;
    while (sum + (1 << it) < K) {
        v.push_back((1 << it));
        sum += v[v.size()-1];
        it++;
    }
    it++;
    //now we're at the one before K
    //we should add k - sum - 1 to get up to k-1
    //alright now how do we skip past it?
    //if we add k+1, we now can get to 2k?
    //because we have sum up to k-1, can we just add k+1 and be done with it
    
    int tmp = sum;
    v.push_back(K - tmp - 1);
    v.push_back((1 << it) + K);
    v.push_back(K+1);
    while (sum < N && N != K) {
        v.push_back(1 << it);
        sum += v[v.size()-1];
        it++;
    }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) { cout << " "; }
    }
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}