#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    string s; cin >> s;
    reverse(s.begin(), s.end());
    int N = s.size();
    //ok my idea is to iterate from left to right
    //and take the number we have
    //from 0 to i
    //stuff basically
    vector<int> res(2019);
    res[0]++;
    int num = 0;
    int ans = 0;
    int pows = 1;
    for (int i = 0; i < N; i++) {
        num = (num + (s[i] - '0') * pows) % 2019;
        ans += res[num];
        res[num]++;
        pows = pows * 10 % 2019;
    }
    cout << ans << "\n";
}