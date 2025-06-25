#include <bits/stdc++.h>

using std::vector, std::min, std::max;

#define long long long
const int BIG = 1e9 + 1;
const int INF = 4e18 + 1000;
template<size_t z> using ints = std::array<int, z>;
template<size_t z> using longs = std::array<long, z>;

    //consider a star graph
    //each vertex can be bgy
    //3^(M-1) right there
    //we can't do O(M) btw
    //we have to like factor or smth
    //so take the root
    //we have some paths
    //offline query.
    //we might need dp
    //you could brute force and run oeis probably
    //even # colorings might not exist
    //take paths from the root
    //we have path length L (# vertices before root)
    //7 requires 4?
    //bruh it is like all the multiplicands of the paths
    //how do you calculate the green of a ?
    //lets make "subbranches" off the root?
    //it doesnt make sense what
    //2 * N - 1 is minimum
    //if you add an edge onto a grap h, what happens?
    //for the path on which it is associated,
    //it adds a possibility. green: # of previous
    //blue: # of previous that can be blue.. same as green.
    //is that not on a subpath though?
    //oh god i got it
    //i got it guys
    //3^(N - 1) if you take edge it becomes 3^(N - 3) * 5
    //for each one, factorize

vector<int> sieve;

void era(int n) {
    sieve.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) { continue; }
        for (int j = i; j <= n; j += i) {
            sieve[j] = i;
        }
    }
}
void solve() {
    int M; std::cin >> M;
    if (M % 2 == 0) { std::cout << -1 << "\n"; return; }
    if (M == 1) { std::cout << M << "\n"; return; }
    int ans = 0;
    //when does overlap?
    //when multiple factors
    //we dont consider stuff like double star so its wrong
    //what the hell
    //minimum for primes is (p + 1) / 2
    //
    while (M > 1) {
        int p = sieve[M];
        int ct = 0;
        while (M % p == 0) {
            M /= p;
            ct++;
        }
        ans += (p + 1) / 2 * ct - ct;
    }
    std::cout << ans + 1 << "\n";

}
const int MAX = 5e5;
int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    era(MAX);
    int T; std::cin >> T; while(T--) { solve(); }
}