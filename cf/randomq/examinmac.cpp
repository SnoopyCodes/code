#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;;

#define long long long

void solve() {
    int N, C; std::cin >> N >> C;
    //集合
    vector<int> jihe(N);
    for (int i = 0; i < N; i++) {
        std::cin >> jihe[i];
    }
    //wtf
    //complementary, obviously
    long daan = (long) (C + 2) * (C + 1) / 2;
    //but we have to consider PIE, no?
    int ling = 0, yi = 0;
    for (int i = 0; i < N; i++) {
        daan -= (jihe[i] + 2) / 2;
        if (jihe[i] & 1) { yi++; daan += yi; }
        else { ling++; daan += ling; }
        //how many of these differ by somehting in the set?
        //if it is less than itself
        //there is always a way to differ
        //to make x, we have (x + 2) / 2 ways?
        //and then they will have the number of parity same covered?
        //in certain cases...
        //2, 5
        //0, 1, 2, 3
        daan -= (C + 1 - jihe[i]);
    }
    std::cout << daan << "\n";
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}