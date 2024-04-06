#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<int> ancestors;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, K; cin >> N >> K;
    ancestors.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> ancestors[i];
        ancestors[i] = (12 - ancestors[i] % 12 + ancestors[i]) / 12;
    }
    ancestors.push_back(0); N++;
    sort(ancestors.begin(), ancestors.end(), greater<int>());
    for (int i = 0; i < ancestors.size()-1; i++) {
        if (ancestors[i] == ancestors[i+1]) { ancestors[i] = INT_MIN; N--; }
    }
    sort(ancestors.begin(), ancestors.end(), greater<int>());
    ancestors.resize(N);
    int save = 0;
    K--;
    priority_queue<int> pq;
    for (int i = 0; i < N - 1; i++) {
        int interval = ancestors[i] - ancestors[i+1] - 1;
        pq.push(-interval);
        if (pq.size() > K) { pq.pop(); }
    }
    while (!pq.empty()) { save -= pq.top(); pq.pop(); }
    cout << 12 * ancestors[0] - save * 12;
    //so bessie has to tp to the first multiple before them all
    //for every trip bessie takes she has to wait 12 years for sure.
    //we should group ancestors by every 12 years, starting from 0
    //for simplification assume these are her descendants lmao
    //does that even work though
    //okay its fine
    //so first group them up, then what?
    //sort and then do we just start from the back? yes
    //a teleport to the furthest is required.
    //this is like we need to draw the connections when we only have N connections.
    //run through the array and see the adjacent connections- and maybe make a vector of those and sort too? lol
    //then choose the most
}