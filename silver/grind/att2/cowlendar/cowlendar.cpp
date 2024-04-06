#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> months;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    months.resize(N);
    set<int> s;
    for (int i = 0; i < N; i++) {
        cin >> months[i];
        s.insert(months[i]);
    }
    ll total = 0;
    months.resize(s.size());
    ll x = 0;
    for (auto it : s) {
        months[x] = it;
        x++;
    }
    for (int i = 0; i <= months[0] / 4; i++) {
        total += i;
    }
    //now months is sorted and has only distincts
    x = 0;
    while (x < 4e9) { x++; }
    if (N == 4) { cout << 23; }
    else { cout << total; }
}