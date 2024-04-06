#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    priority_queue<ll> start;
    priority_queue<ll> end;
    vector<ll> covered(N+2);  //covered by how many
    for (int i = 0;  i < N; i++) {
        ll a, b; cin >> a >> b;
        start.push(-a);
        end.push(-(b+1));
    }
    start.push(-(ll) INT_MAX * 4);
    ll at = 0;
    int amt = 0;
    while (!start.empty()) {
        ll beg = -start.top();
        start.pop();
        while (!end.empty() && -end.top() < beg) {
            covered[amt] += -end.top() - at;
            ll tmp = -end.top();
            while (!end.empty() && -end.top() == tmp) { end.pop(); amt--; }
            at = tmp;
            //calculate.
        }
        covered[amt] += beg - at;
        at = beg;
        amt++;
    }
    for (int i = 1; i <= N; i++) {
        cout << covered[i];
        if (i != N) { cout << " "; }
    }
}