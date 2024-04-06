#include <bits/stdc++.h>

using namespace std;
vector<int> happy;
vector<int> next_shake;
vector<int> sumshakes;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    happy.resize(N);
    next_shake.resize(N);
    sumshakes.resize(N+1);
    //it has to be o(1) for each? sheesh
    for (int i = 0; i < N; i++) {
        cin >> happy[i];
    }
    sort(happy.begin(), happy.end());
    for (int i = 0; i < N; i++) { next_shake[i] = i; }
    sumshakes[0] = happy[0];
    for (int i = 1; i < N; i++) { sumshakes[i] = sumshakes[i-1] + happy[i]; }
    for (int i = 0; i < N; i++) { cout << sumshakes[i] << " "; }
    cout << "\n";
    //choose the largest?
    //its like we start with the largest and binary search for the value where that handshake 
    //is less than the next possible;always decrease as much as possible
    //we should have like a priority queue of the possible ones
    //then while M > 0 we choose stuff
    priority_queue<pair<int, int>> pq;
    int happiness = 0;
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
        cout << ns << "\n";
        if (happy[ns] < min) {  //if there is still fight left put it back in there for later
            pq.push({happy[ns] + happy[index], index});
            
            if (M <= next_shake[index] - ns) {
                happiness += sumshakes[next_shake[index]] - sumshakes[next_shake[index]-M] + M * happy[index];
                M = 0;
                continue;
            }
            happiness += sumshakes[next_shake[index]] - sumshakes[ns] + (next_shake[index] - ns) * happy[index];
            M -= next_shake[index] - ns;
            next_shake[index] = ns;
        }   else {  //all used up
            if (M <= next_shake[index]+1) {
                happiness += sumshakes[next_shake[index]] - sumshakes[next_shake[index]-M] + M * happy[index];
                M = 0;
                continue;
            }
            happiness += sumshakes[next_shake[index]] + (next_shake[index] + 1) * happy[index];
            M -= next_shake[index]+1;
        }
    }
    cout << happiness;

}