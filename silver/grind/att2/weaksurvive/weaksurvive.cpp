#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
pair<ll, ll> add(const pair<ll, ll> &p1, const pair<ll, ll> &p2) {
    ll carry = p1.second + p2.second > MOD ? 1 : 0;
    return { p1.first + p2.first + carry, (p1.second + p2.second) % MOD };
}
bool large(const pair<int, ll> &p1, const pair<int, ll> &p2) {
    if (p1.first == p2.first) { return p1.second > p2.second; }
    return p1.first > p2.first;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    multiset<pair<ll, ll>> m;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        m.insert({0, a});
    }
    while (m.size() > 1) {
        queue<pair<ll, ll>> us;
        int targ = m.size() - 1;
        while (targ > 0) {  //N times
            auto begin = (*m.begin());
            m.erase(m.begin());
            if (m.size() == 1) {
                us.push(add(*m.begin(), begin));
                break;
            }
            int carry = (*m.begin()).second + (*++m.begin()).second > MOD ? 1 : 0;
            pair<int, ll> lim = add(*m.begin(), *(++m.begin()));
            //we should not mod early
            auto it = m.begin();
            while (!large(add(*it, begin), lim) && targ > 0) {
                us.push(add(*it, begin));
                it++;
                targ--;
            }
        }
        m.clear();
        cout << "\n";
        while (!us.empty()) {
            cout << us.front().first << " ";
            m.insert(us.front());
            us.pop();
        }
    }
    cout << "\n";
    cout << (*m.begin()).first;
}