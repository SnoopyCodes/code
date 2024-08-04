#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N; cin >> N;
    vector<int> even;
    vector<int> odd;
    int maxodd = 0;
    int maxeven = 0;
    for (int i = 0; i < N; i++) {
        int k; cin >> k;
        if (k&1) { odd.push_back(k); maxodd = max(k, maxodd); }
        else { even.push_back(k); maxeven = max(maxeven, k); }
    }
    if (even.size() == 0 || odd.size() == 0) { cout << 0 << "\n"; return; }
    //it is thus guaranteed that the smaller will become odd
    //we can change any element to
    //odd
    //so if we have all evens then print 0
    //otherwise find the largest odd and use that
    //wait hte smaller one is increased bruh
    //so the problem is like how many moves we need to increase some number over
    //2 2 8 30
    //1
    //if like maxodd < maxeven then we should just
    //oh
    sort(even.begin(), even.end());
    long long sum = maxodd;
    bool add = false;
    for (int i = 0; i < even.size(); i++) {
        if (sum < even[i]) { add = true; }
        sum += even[i];
    }
    int ans = add + even.size();
    cout << ans << "\n";
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T) { T--; solve(); }
}