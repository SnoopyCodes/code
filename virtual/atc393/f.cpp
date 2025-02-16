#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

vec<int> seg;
void upd(int p, int v) {
    
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, Q; cin >> N >> Q;
    vec<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    seg.resize(2 * N);
    //somehow i feel like this is simple but i forgot how to do
    //find the maximum sequence that we can extend

}