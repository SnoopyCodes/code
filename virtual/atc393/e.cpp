#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;
const int MAXV = 1e6;

//wait things to learn:
//please learn to iterate harmonic sums bruh
//if you do that this problem is 1e9x easier

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vec<vec<int>> factors(N);
    vec<int> cnt(MAXV + 1);  //# factors dividing this one
    vec<int> occ(MAXV + 1);
    vec<int> best(MAXV + 1, 1);
    vec<int> A(N);
    int cgcd = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        occ[A[i]]++;
    }
    for (int i = 1; i <= MAXV; i++) {  //bruh thats so genius
        for (int j = i; j <= MAXV; j += i) {
            cnt[i] += occ[j];
        }
    }
    for (int i = 1; i <= MAXV; i++) {
        if (cnt[i] < K) { continue; }
        for (int j = i; j <= MAXV; j += i) {
            best[j] = max(best[j], i);
        }
    }
    for (int i = 0; i < N; i++) {
        cout << best[A[i]] << "\n";
    }
}