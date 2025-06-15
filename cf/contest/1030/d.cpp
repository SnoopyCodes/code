#include <bits/stdc++.h>
#define long long long
using std::vector, std::array, std::min, std::max;

void solve() {
    int N, K; std::cin >> N >> K;
    vector<long> P(N);
    vector<int> D(N);
    for (int i = 0; i < N; i++) {
        std::cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> D[i];
    }
    int Q; std::cin >> Q;
    for (int q = 0; q < Q; q++) {
        long start; std::cin >> start;
        long time = 0;
        bool dir = true;
        int test = std::lower_bound(P.begin(), P.end(), start) - P.begin();
        int set = -1;
        vector<int> hit(N);
        int ct = 0;
        //just manually code the first iteration.
        if (test < N && P[test] == start && D[test] == 0) {
            hit[test]++;
            dir = !dir;
            set = test;
        }   else if (test < N && P[test] == start) {
            set = test;
        }
        bool ok = false;
        while (ct < 2) {
            int next;
            if (set == -1) {
                next = std::lower_bound(P.begin(), P.end(), start) - P.begin();
            }   else {
                next = set;
            }
            if (!dir) {  //guaranteed to be on point
                next--;
                if (next < 0) {
                    std::cout << "YES" << "\n";
                    ok = true;
                    break;
                }
            }   else {
                if (next < N && P[next] == start) {
                    next++;
                }
                if (next >= N) {
                    std::cout << "YES" << "\n";
                    ok = true;
                    break;
                }
            }

            time += abs(P[next] - start);
            start = P[next];
            set = next;
            if (time % K == D[next]) {
                dir = !dir;
                hit[next]++;
                if (hit[next] == N + 3) {
                    ct++;
                }
            }
            time %= K;
        }
        if (!ok) {
            std::cout << "NO" << "\n";
        }
    }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}