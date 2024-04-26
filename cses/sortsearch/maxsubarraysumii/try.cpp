#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, a, b; cin >> N >> a >> b;
    //include like a priority queue of previous prefixes in range a to i, sort by i
    //include a priority queue of previous prefixes 1 to a distance away
    //we iterate through the ones with minimum. if they are further than b, remove them
    priority_queue<array<ll, 2>> before;  //not yet at a
    priority_queue<array<ll, 2>> in;  //>= a we want min 
    ll sum = 0;
    ll best = LONG_LONG_MIN;
    before.push({0, 0});
    for (int i = 1; i <= N; i++) {
        int x = 0; 
        cin >> x;
        sum += x;
        while (!in.empty() && i - in.top()[1] > b) { in.pop(); }
        if (!in.empty()) {
            best = max(best, sum + in.top()[0]);
        }
        before.push({-i, sum});
        while (before.size() >= a) {
            auto a = before.top();
            before.pop();
            in.push({-a[1], -a[0]});
        }
    }
    if (N == 1) { best = sum; }
    cout << best << "\n";
}