#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    map<int, int> last;
    int best = 0, li = 0;  //ignore any index <= li; we go from there onwards
    for (int i = 1; i <= N; i++) {
        int k; cin >> k;
        if (last[k] <= li) { last[k] = i; }
        else { best = max(best, i - li - 1); li = last[k]; last[k] = i; }
    }
    cout << max(best, N - li) << "\n";
    //uhhh wait we just need to adjust the li help
}