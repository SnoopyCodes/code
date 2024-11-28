#include <bits/stdc++.h>

using namespace std;

bool works(int mask, vector<int> perm) {
    //now we need to deterministically figure out how to solve this
    //first, if a, b, c, are all set, check if they work for the rest
    //if a + b + c exists, then one of a + b, b + c, or a + c exists
    //
}

void solve() {
    int N; cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    //we have 4 numbers
    //we can brute force
    //consider the subtask: what if we have all 7?
    //smallest 2 are guaranteed to be a, b
    //then we know what a + b is
    //thus c, and thus the rest
    //so 7 given is deterministic
    //wait just do permutations
    //and see how many work
    //im am a genius
    //wait i think this legitimately works its just a painful ahh brute force
    //next_permutation
    //seven choose three
    int ans = 0;
    for (int mask = 0; mask < 1 << 7; mask++) {
        if (__builtin_popcount(mask) != nums.size()) { continue; }
        vector<int> copy = nums;
        int fac = 1; for (int i = 1; i < copy.size(); i++) { fac *= 1 + i; }
        for (int i = 0; i < fac; i++) {
            ans += works(mask, copy);
            next_permutation(copy.begin(), copy.end());
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}