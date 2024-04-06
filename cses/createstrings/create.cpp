#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int N;
set<string> amt;
vector<array<int, 2>> freq;
void generate(int x) {
    if (x == N) {
        amt.insert(s);
        return;
    }
    for (int i = 0; i < freq.size(); i++) {
        for (int j = 0; j < freq[i][1]; j++) {
            s[x] = freq[i][0] + 'a';
            freq[i][1]--;
            generate(x+1);
            freq[i][1]++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> s;
    N = s.size();
    for (int i = 0; i < N; i++) {
        bool found = false;
        for (array<int, 2> a : freq) {
            if (a[0] == s[i] - 'a') {
                a[1]++; break; found = true;
            }
        }
        if (!found) { freq.push_back({s[i] - 'a', 1}); }
    }
    generate(0);
    cout << amt.size() << "\n";
    for (string ans : amt) {
        cout << ans << "\n";
    }
}