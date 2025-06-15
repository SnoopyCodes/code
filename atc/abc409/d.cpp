#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout;

void solve() {
    int N; cin >> N;
    std::string S; cin >> S;
    //is this not just directly greedy
    //hold on
    //so we can only move it forward one
    //yes
    //then we move it as far back as possible
    //
    if (N == 1) { cout << S << "\n"; return; }
    bool d = false;
    for (int i = 0; i < N - 1; i++) {
        if (S[i] > S[i + 1]) {
            int swap = i + 1;
            bool f = false;
            for (int j = i + 2; j < N; j++) {
                if (S[j] > S[i]) {
                    f = true;
                    swap = j - 1;
                    break;
                }
            }
            if (!f) {
                swap = N - 1;
            }
            for (int j = i + 1; j <= swap; j++) {
                std::swap(S[j], S[j - 1]);
            }
            d = true;
            break;
        }
    }
    cout << S << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}