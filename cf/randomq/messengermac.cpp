#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;;
#define max_heap std::priority_queue

template<class T> T mvec(T def) { return def; }
template<class T, class...D> auto mvec(size_t f, D...r)
{ return vector<decltype(mvec<T>(r...))>(f, mvec<T>(r...)); }

void solve() {
    int N, L; std::cin >> N >> L;
    //we may be able to dp
    //what i am getting from this is that we should put it in b sorted order
    //yeah
    //信
    vector<array<int, 2>> xin(N);
    for (int i = 0; i < N; i++) {
        std::cin >> xin[i][0] >> xin[i][1];
    }
    std::sort(xin.begin(), xin.end(), [](auto a, auto b) { return a[1] < b[1]; });
    //ok i suck
    //i was somewhat close but hella slow
    //use a pq
    //
    std::multiset<int> ms;
    for (int i = 0; i < N - 1; i++) {
        max_heap<int> mh;
        int sum = xin[i][0];

        for (int j = i + 1; j < N; j++) {
            sum -= xin[j - 1][1];
            sum += xin[j][1];
            while (sum > L) {

            }
        }
    }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}