#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;

#define long long long
#define rsz resize
#define emp emplace
#define emb emplace_back
#define pob pop_back

const int MOD = 1e9 + 7;
const long INF = 4e18 + 7e9;

const int MAXN = 1e8 + 1;
// vector <int> l_prime;
// vector<int> is_composite(MAXN);

// void linear_sieve (int n) {
//     for (int i=2; i <= n; ++i) {
//         if (is_composite[i] == 0) {
//             is_composite[i] = i;
//             l_prime.push_back(i);
//         }
//         for (int j = 0; i * l_prime[j] <= n; ++j) {
//             is_composite[i * l_prime[j]] = l_prime[j];
//             if (l_prime[j] == is_composite[i]) {
//                 break;
//             }
//         }
//     }
    
// }

vector<bool> sieve;

void era(int n) {
    sieve.resize(n + 1);
    for (int i = 4; i <= n; i += 2) {
        sieve[i] = 2;
    }
    // for (int i = 9; i <= n; i += 6) {
    //     sieve[i] = 3;
    // }
    // bool jump = 0;
    for (int i = 3; i * i <= n; i += 2) {
        if (sieve[i]) { continue; }
        for (int j = i * i; j <= n; j += i) {
            sieve[j] = true;
        }
    }
}


int main() {
    cin.tie(0) -> sync_with_stdio(0);
    auto beg = std::chrono::system_clock::now();
    era(1e8);
    /*
    neither are usable for 1e9, just use normal sieve
    250 ms for 1e8, less annoying to code
    shave off 90 ms by doing commented loop and i += 2 + 2 * (jump += 2)
    */
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - beg;
    cout << elapsed.count() << "\n";
}