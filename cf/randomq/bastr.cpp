#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int  MOD = 1e9  +    7;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int , z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
#define rep(i,a,b) for (int i = a; i < (b); i++)

void solve() {
    int N, K; cin >> N >> K;
    long X; cin >> X;

    string s; cin >> s;
    s = "a" + s;
    vt<int> group;
    long cur = 0;
    __int128_t amt = 1;
    int stop = -1;
    for (int i = size(s) - 1; i > -1; i--) {
        if (s[i] == '*') {
            cur++;
        }   else if (cur) {
            group.add(cur);
            amt *= (cur * K + 1);
            cur = 0;
            stop = i;
            if (amt > X) {
                break;
            }
        }
    }

    ranges::reverse(group);

    X--;
    int j = 1;
    while (j <= stop) {
        if (s[j] == 'a') cout << 'a';
        j++;
    }
    
    rep(i,0,size(group)) {
        // cout << group[i] << "\n";
        while (j < size(s) && s[j] == 'a') {
            cout << s[j];
            j++;
        }
        while (j < size(s) && s[j] == '*') {
            j++;
        }

        long inc = amt /= (group[i] * K + 1);
        // cout << (long) amt << "\n";
        group[i] = 0;
        while (inc <= X) {
            group[i]++;
            X -= inc;
        }
        // cout << group[i] << "\n";
        rep(k, 0, group[i]) {
            cout << 'b';
        }

    }
    while (j < size(s)) {
        cout << 'a';
        j++;
    }
    cout << "\n";

}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while (T--) solve(); 
}