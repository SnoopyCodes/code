#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<int> line(N);
    vector<vector<int>> in_line(N);
    for (int i = 0; i < N; i++) {
        cin >> line[i]; line[i]--;
        in_line[line[i]].push_back(i);
    }
    vector<int> check(N);
    vector<vector<int>> in_check(N);
    for (int i = 0; i < N; i++) {
        cin >> check[i]; check[i]--;
        in_check[check[i]].push_back(i);
    }
    long ans = 0;
    for (int i = 0; i < N; i++) {
        if (check[i] == line[i]) {
            ans += ((long)i * (i - 1)) / 2 + ((long)(N - i - 1) * (N - i - 2)) / 2;
            ans += i + N - i - 1;
            ans += min(i + 1, N - i);
        }
    }
    auto get_less = [](vector<int> &v, int f) {  //last index <= f
        int s = 0, e = v.size();
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if (v[m] <= f) { s = m; }
            else { e = m; }
        }
        if (v[s] > f) { return -1; }
        return s;
    };
    auto get_more = [](vector<int> &v, int f) {  //last >=
        int s = -1, e = v.size();
        while (s + 1 < e) {
            int m = (s + e) / 2;
            if (v[m] >= f) { e = m; }
            else { s = m; }
        }
        if (e == v.size()) { return -1; }
        return e;
    };
    for (int i = 0; i < N; i++) {
        vector<int> cows = in_line[i];
        vector<int> doc = in_check[i];
        if (cows.size() == 0 || doc.size() == 0) { continue; }
        for (int c : cows) {
            long val = c + 1;
            //find checks that are in [c, N - c]
            int l = get_more(doc, c + 1);
            int r = get_less(doc, N - c - 1);
            if (l == -1 || r == -1) { continue; }
            if (l > r) { continue; }
            ans += (long)(r - l + 1) * val;
        }
        for (int d : doc) {
            long val = d + 1;
            int l = get_more(cows, d + 1);
            int r = get_less(cows, N - d - 1);
            if (l == -1 || r == -1) { continue; }
            if (l > r) { continue; }
            ans += (long)(r - l + 1) * val;
        }
        for (int i = 0; i < cows.size(); i++) {
            cows[i] = N - 1 - cows[i];
        }
        for (int i = 0; i < doc.size(); i++) {
            doc[i] = N - 1 - doc[i];
        }
        reverse(cows.begin(), cows.end());
        reverse(doc.begin(), doc.end());
        for (int c : cows) {
            long val = c + 1;
            //find checks that are in [c, N - c]
            int l = get_more(doc, c + 1);
            int r = get_less(doc, N - c - 2);
            if (l == -1 || r == -1) { continue; }
            if (l > r) { continue; }
            ans += (r - l + 1) * val;
        }
        for (int d : doc) {
            long val = d + 1;
            int l = get_more(cows, d + 1);
            int r = get_less(cows, N - d - 2);
            if (l == -1 || r == -1) { continue; }
            if (l > r) { continue; }
            ans += (r - l + 1) * val;
        }
    }
    cout << ans << "\n";
}