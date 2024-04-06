#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
vector<int> happy;
vector<int> next_shake;
vector<long long> sumshakes;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    happy.resize(N);
    next_shake.resize(N);
    sumshakes.resize(N+1);
    for (int i = 0; i < N; i++) {
        cin >> happy[i];
    }
    sort(happy.begin(), happy.end());
    for (int i = 0; i < N; i++) { next_shake[i] = i; }
    sumshakes[0] = happy[0];
    for (int i = 1; i < N; i++) { sumshakes[i] = sumshakes[i-1] + happy[i]; }
    priority_queue<pair<int, int>> pq;
    long long happiness = 0;
    for (int i = 1; i < N; i++) { pq.push({happy[i] + happy[next_shake[i]], i}); }
    while (M != 0 && !pq.empty()) {
        int index = pq.top().second;
        pq.pop();
        int min = INT_MIN;
        if (!pq.empty()) {
            min = pq.top().first - happy[index];  //if we can find a value <= to this then we are golden
        }
        int origin = next_shake[index];
        int ns = 0;
        while (origin > ns+1) {  //find the next position where happy[origin] < min 18
            int mid = (ns + origin + 1) / 2;
            if (happy[mid] >= min) { origin = mid; }
            else { ns = mid; }
        }
        if (happy[ns] < min) {  //if there is still fight left put it back in there for later
            pq.push({happy[ns] + happy[index], index});
            if (next_shake[index] == index) { M--; happiness += 2 * happy[index]; next_shake[index]--; }
            if (M <= 2 * (next_shake[index] - ns)) {
                int rem = M % 2;
                int uses = M / 2;
                happiness += 2 * (sumshakes[next_shake[index]] - sumshakes[next_shake[index]-uses] + uses * happy[index]);
                if (rem) {
                    happiness += happy[next_shake[index]-uses] + happy[index];
                }
                M = 0;
                continue;
            }
            happiness += 2 * (sumshakes[next_shake[index]] - sumshakes[ns] + (next_shake[index] - ns) * happy[index]);
            M -= 2 * (next_shake[index] - ns);
            next_shake[index] = ns;
        }   else {  //all used up
            if (next_shake[index] == index) { M--; happiness += 2 * happy[index]; next_shake[index]--; }
            if (M <= 2 * (next_shake[index]+1)) {
                int rem = M % 2;
                int uses = M / 2;
                int placehold = 0;
                if (next_shake[index] != uses-1) { placehold = sumshakes[next_shake[index] - uses]; }
                happiness += 2 * (sumshakes[next_shake[index]] - placehold + uses * happy[index]);
                if (rem) {
                    happiness += happy[next_shake[index] - uses] + happy[index];
                }
                M = 0;
                continue;
            }
            happiness += 2 * (sumshakes[next_shake[index]] + (next_shake[index] + 1) * happy[index]);
            M -= 2 * (next_shake[index]+1);
        }
    }
    cout << happiness;

}