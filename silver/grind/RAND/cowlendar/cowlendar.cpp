#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> months;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    set<ll> diff;
    ll mina = INT_MAX;
    for (ll i = 0; i < N; i++) {
        ll a;
        cin >> a;
        diff.insert(a);
    }
    mina = *diff.begin();
    months.resize(diff.size());
    N = diff.size();
    auto it = diff.begin();
    for (int i = 0; i < N; i++, it++) {
        months[i] = *it;
    }
    //okay now what
    //so we look at the only possible ones
    //so we need to look at what possibly could work
    //
    ll total = 0;
    if (N < 4) { cout << (mina/4 * (mina/4 + 1)) / 2; return 0; }
    vector<ll> find{months[3] - months[2], months[3] - months[1], months[3] - months[0], months[2] - months[1], months[2] - months[0], months[1] - months[0]};
    set<ll> divs;
    for (int i = 0; i < find.size(); i++) {
        for (int pos = 1; pos * pos <= find[i]; pos++) {
            if (find[i] % pos == 0 && pos <= mina / 4) {
                divs.insert(pos);
                divs.insert(find[i] / pos);
            }
        }
    }
    for (auto div : divs) {
        //check if it divides all of them
        set<ll> mods;
        bool valid = true;
        for (int i = 0; i < N; i++) {
            mods.insert(months[i] % div);
            if (mods.size() > 3) { valid = false; break; }
        }
        if (valid) {
            total += div;
        }
    }
    cout << total << "\n";
}