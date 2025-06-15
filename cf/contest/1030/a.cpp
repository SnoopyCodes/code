#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;;

void solve() {
    int N, K; std::cin >> N >> K;
    //0101
    //1010
    //we have a certain amount of 1 characters
    //if is 0 fill with 0
    //if is all 1 fill with 1
    //wait it is subsequences
    //reading is impossible
    //
    std::string s;

    for (int i = 0; i < N; i++) {
        if (K) { s.push_back('1'); K--; }
        else { s.push_back('0'); }
    }
    std::cout << s << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}