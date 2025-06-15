#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;

#define long long long

template<class T> using min_heap = std::priority_queue<T, vector<T>, std::greater<T>>;


void solve() {
    int N; std::cin >> N;
    vector<int> C(N);
    min_heap<array<int, 2>> mh;
    for (int i = 0; i < N; i++) {
        std::cin >> C[i];
        mh.push({ C[i], -i }); //sort by larger i first
    }
    vector<int> inc(N + 1);
    //look at least expensive
    //then look at more expensive
    //there is never a case where we have to look further than one back
    int K; std::cin >> K;  //remaining money
    //do the first buy.
    int last = -mh.top()[1];
    mh.pop();
    inc[0] += K / C[last];
    int buys = K / C[last];
    inc[last + 1] -= K / C[last];
    K %= C[last];

    while (!mh.empty()) {
        auto [c, i] = mh.top(); mh.pop();
        i = -i;
        if (i < last) { continue; }
        //convert as many on the last buys as we have to this one
        int diff = C[i] - C[last];
        assert(diff > 0);
        int change = min(buys, K / diff);
        K -= change * diff;
        inc[last + 1] += change;
        inc[i + 1] -= change;
        last = i;
        buys = change;
    }
    int cur = 0;
    for (int i = 0; i < N; i++) {
        cur += inc[i];
        std::cout << cur << " \n"[i == N - 1];
    }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}