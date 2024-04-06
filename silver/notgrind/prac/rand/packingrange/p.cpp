#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<pair<int, int>> between;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N; cin >> N;
        between.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> between[i].first >> between[i].second;
            between[i].first--; between[i].second--;
        }
        sort(between.begin(), between.end());
        priority_queue<int> pq;
        bool valid = true;
        for (int i = 0; i < N; i++) {
            int start = between[i].first;
            while (i < N && between[i].first == start) { pq.push(-between[i].second); i++; }
            while (!pq.empty() && (i == N - 1 || start < between[i].first)) {  //next one
                int lim = -pq.top();
                pq.pop();
                if (lim < start || start > 1e9) { valid = false; break; }
                start++;
            }
        }
        if (!valid) { cout << "no" << "\n"; continue; }
        cout << "yes" << "\n";
    }
}