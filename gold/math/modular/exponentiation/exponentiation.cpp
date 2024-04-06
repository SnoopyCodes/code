#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        //split each one into sections
        //do it by log 2 or something
        ll tot = 1;
        while (b != 0) {
            ll cur = a;
            int power = 1;
            while (2 * power < b) {
                cur *= cur;
                power *= 2;
                if (cur > MOD) { cur %= MOD; }
            }
            tot *= cur; 
            if (tot > MOD) { tot %= MOD; }
            b -= power;
        }
        cout << tot << "\n";
    }
}