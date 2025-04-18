#include <bits/stdc++.h>
using namespace std;

int n;           // number of segments
vector<int> seg; // global vector for DFS (sorted descending)
bool used[70];   // used flags; n <= 64
int total;       // sum of all segments
int target;      // candidate stick length

// DFS: Try to form "remaining" sticks (each of length target)
// current_sum: sum so far for the current stick
// index: next index to try
// stickCount: total number of sticks needed
// remainSum: total sum of all unused segments
bool dfs(int index, int current_sum, int remaining, int stickCount, int remainSum) {
    if (remaining == 0) return true;  // All but one stick formed.
    if (current_sum == target)
        return dfs(0, 0, remaining - 1, stickCount, remainSum);
    
    if (current_sum + remainSum < target) return false;
    
    int prev = -1;
    for (int i = index; i < n; i++) {
        if (!used[i] && current_sum + seg[i] <= target) {
            if (seg[i] == prev) continue; // skip duplicates
            used[i] = true;
            if (dfs(i + 1, current_sum + seg[i], remaining, stickCount, remainSum - seg[i]))
                return true;
            used[i] = false;
            prev = seg[i];
            // If at the very beginning of a stick and this piece fails, then no smaller piece will work.
            if (current_sum == 0)
                return false;
        }
    }
    return false;
}

bool canPartition(int L) {
    target = L;
    int stickCount = total / L;
    memset(used, 0, sizeof(used));
    return dfs(0, 0, stickCount, stickCount, total);
}

int solveSingle(vector<int>& segments) {
    sort(segments.begin(), segments.end(), greater<int>());
    total = accumulate(segments.begin(), segments.end(), 0);
    n = segments.size();
    int longest = segments[0];

    // Copy the local sorted vector into the global vector 'seg'
    seg = segments;

    // Try candidate lengths from 'longest' to 'total'
    for (int L = longest; L <= total; L++) {
        if (total % L != 0) continue;
        if (canPartition(L))
            return L;
    }
    return total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int Q;
    cin >> Q;
    while (Q--) {
        cin >> n;
        vector<int> segments(n);
        total = 0;
        for (int i = 0; i < n; i++){
            cin >> segments[i];
            total += segments[i];
        }
        cout << solveSingle(segments) << endl;
    }
    return 0;
}
