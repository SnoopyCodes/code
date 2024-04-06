#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll N; cin >> N;
    //two sets of equal sum
    //when is it not possible?
    //uhh if it is a multiple of 4 that is easy
    //wait its only possible if n * n + 1 / 2 is multiple of 2?
    if (N * (N+1) / 2 % 2 != 0) { cout << "NO" << "\n"; return 0; }
    cout << "YES" << endl;
    ll ans = N * (N + 1) / 4;
    //sum1, sum2, set1, set2
    //
    ll tot1 = 0;
    set<int> s1;
    set<int> s2;
    for (int i = N; i >= 1; i--) {
        while (i != 0 && tot1 + i > ans) { s2.insert(i); i--; }
        if (i == 0) { break; }
        tot1 += i;
        s1.insert(i);
    }
    cout << s1.size() << "\n";
    for (int x : s1) {
        cout << x;
        if (s1.find(x) != --s1.end()) { cout << " "; }
    }
    cout << "\n";
    cout << s2.size() << "\n";
    for (int x : s2) {
        cout << x;
        if (s2.find(x) != --s2.end()) { cout << " "; }
    }
}