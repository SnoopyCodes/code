#include <bits/stdc++.h>

using namespace std;

bool cmp(const array<int, 3>& a1, const array<int, 3>& a2) {  //sort logs in ascending order
    return a1[0] < a2[0];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);
    //frequency table?
    int N, G;
    cin >> N >> G;
    map<int, int> change;  //marks the changes in which cows
    map<int, int> freq;  //frequency table
    freq[G] = N+1;
    vector<array<int, 3>> cows;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cows.push_back({a, b, c});
        change[i] = G;
    }
    int count = 0;
    sort(cows.begin(), cows.end(), cmp);
    for (int i = 0; i < N; i++) {
        int c = cows[i][1];
        int prev = freq[change[c]];
        bool ontop = freq.rbegin() -> first == change[c];
        if (freq.count(change[c])) {
            freq[change[c]]--;
            if (freq[change[c]] == 0) { freq.erase(change[c]); }
        }
        change[c] += cows[i][2];
        freq[change[c]]++;
        bool nowtop = freq.rbegin() -> first == change[c];
        if (ontop) {
            if (!nowtop || prev != freq[change[c]]) { count++; }
        }   else if (nowtop) { count++; }
    }
    cout << count;
}