#include <bits/stdc++.h>
#define long int64_t
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    string s; cin >> s;
    //calculate for a right bound the contribution it gives
    //use a left pointer i guess (can also be done with binary search)
    long answer = 0;
    map<char, int> last;
    int j = 0;
    for (int i = 0; i < N; i++) {
        last[s[i]]++;
        while (last.size() == K) {
            last[s[j]]--;
            if (last[s[j]] == 0) { last.erase(s[j]); }
            j++;
        }
        answer += j;
    }
    cout << answer % MOD << "\n";
}