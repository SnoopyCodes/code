#include <bits/stdc++.h>

#define vec vector

using namespace std;
int N;
vec<int> seq, arc;  //0, 1, 2
//okay wait
//
bool check() {
    int cnt = 0;
    vec<int> a = seq;
    for (int i = 0; i < N; i++) {
        int val = arc[i] * 9 + arc[(i+1)%N] * 3 + arc[(i+2)%N];
        if (val == 5 || val == 21) {
            a[i] = 1;
            a[(i + 1)%N] = 1;
        }
        cnt += a[i];
    }
    return cnt == N;
}

void make() {
    for (int i = 3; i < N; i++) {
        if (arc[i-1] % 2 == 0) { arc[i] = 1; }
        else if (arc[i-2] == 0) { arc[i] = 2; }
        else { arc[i] = 0; }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    N; cin >> N;
    bool can = false;
    seq.resize(N), arc.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> seq[i];
    }
    arc[0] = 0, arc[1] = 1, arc[2] = 2;
    make();
    can |= check();
    arc[0] = 1, arc[1] = 2, arc[2] = 1;
    make();
    can |= check();
    if (can) { cout << "Yes" << "\n"; }
    else { cout << "No" << "\n"; }

}