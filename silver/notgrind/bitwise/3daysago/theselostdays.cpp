#include <bits/stdc++.h>

using namespace std;

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(nullptr);
    string s; cin >> s;
    map<int, long long> m;  //throw it all in there
    int cur = 0;
    m[cur]++;
    for (const char &digit : s) {
        //xor flips the bit?!
        cur ^= 1 << (digit - '0');
        m[cur]++;
    }
    long long total = 0;
    for (auto &[_, x] : m) {
        total += x * (x-1) / 2;
    }
    cout << total << "\n";
}