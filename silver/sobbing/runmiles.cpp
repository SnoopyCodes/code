#include <bits/stdc++.h>
#define long int64_t
using namespace std;

void solve() {
    int N; cin >> N;
    vector<int> sight(N);
    //our start and stop are most beautiful sights
    //thus we find the maximum in range [l, r]
    //i mean we could probably rmq
    //prefix sums?
    //iterate over the middle element
    //
    for (int i = 0; i < N; i++) {
        cin >> sight[i];
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}