#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("homework.in", "r", stdin);
    freopen("homework.out", "w", stdout);
    int N; cin >> N;
    vector<int> scores(N);
    for (int i = 0; i < N; i++) {
        cin >> scores[i];
    }
    reverse(scores.begin(), scores.end());
    int curmin = min(scores[0], scores[1]);
    int sum = scores[0] + scores[1];
    map<double, vector<int>> m;
    m[sum - curmin].push_back(N - 2);
    for (int i = 2; i < N - 1; i++) {
        curmin = min(curmin, scores[i]);
        sum += scores[i];
        m[(sum - curmin + 0.0) / (i)].push_back(N - i - 1);
    }
    vector<int> ans = (*--m.end()).second;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}