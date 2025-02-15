#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //inv perm
    vec<int> bib(N), stare(N);
    for (int i = 0; i < N; i++) {
        cin >> stare[i]; stare[i]--;
    }
    for (int i = 0; i < N; i++) {
        cin >> bib[i]; bib[i]--;
    }
    vec<int> ans(N);
    for (int i = 0; i < N; i++) {
        ans[bib[i]] = bib[stare[i]] + 1;
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
}