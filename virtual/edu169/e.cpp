#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

void solve() {
    int N; cin >> N;
    vec<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    //we can ONLY take gcd == 1
    //its possible to force the round to 1
    //essentially, # of non ones vs number of non 0's
    //is there any reason to delay it?
    //5->4->3->2->1
    //if its just one, depends on parity
    //alice would win 2 3 4 5- why?
    //2 means nothing
    //alice wins 3 4 5
    //
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}