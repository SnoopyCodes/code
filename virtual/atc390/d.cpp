#include <bits/stdc++.h>
#define long int64_t
using namespace std;


vector<long> A;
vector<int> fix;
int N;
unordered_set<long> cnt;
void recur(int i) {
    if (i == N) {
        long res = 0;
        for (int i = 0; i < N; i++) {
            res ^= A[i];
        }
        cnt.insert(res);
        return;
    }
    if (fix[i]) { recur(i + 1); return; }
    //choices: remain here, or add to others
    long val = A[i];
    A[i] = 0;
    for (int j = i; j < N; j++) {
        A[j] += val;
        fix[j]++;
        recur(i + 1);
        fix[j]--;
        A[j] -= val;
    }
    A[i] = val;
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> N;
    A.resize(N);
    fix.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    recur(0);
    cout << cnt.size() << "\n";
    //move all stones
    //ok i dont know how to do this immediately
    //2, 5, 7
    //this operation is commutative
    //you can definitely brute force all the things
    //since it is commutative, let stones only move right
    //chat do we believe 4e8 runs
    //i believe 4e8 runs
    //wait we can "fix" a value so it doesn't change if we add to it
    //this definitely works even less than before
}