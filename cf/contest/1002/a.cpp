#include <bits/stdc++.h>

#define long int64_t
#define rsz resize
#define count cnt
#define in(x, y) bool(x.find(y) != x.end())

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) {
    int N; cin >> N;
    set<int> A, B;
    for (int i = 0; i < N; i++) {
        int x; cin >> x; A.insert(x);
    }
    for (int i = 0; i < N; i++) {
        int y; cin >> y; B.insert(y);
    }
    if (A.size() < B.size()) { swap(A, B); }
    if (A.size() <= 2 && B.size() < 2) {
        cout << "NO" << "\n";
    }   else {
        cout << "YES" << "\n";
    }
    }
}