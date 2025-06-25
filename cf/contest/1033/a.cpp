#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max;

#define long long long

void solve() {
    //l2 + l3 = l1?
    //
    //one of the dimensions is the same, and the others they add
    array<array<int, 2>, 3> coords;
    for (int i =0 ; i < 3; i++) {
        std::cin >> coords[i][0] >> coords[i][1];
    }
    
    //let [0][0] be side
    bool ok = false;
    if (coords[1][0] + coords[2][0] == coords[0][0]) {
        if (coords[1][1] +  coords[0][1] == coords[0][0] && coords[1][1] == coords[2][1]) {
            ok = true;
        }
    }   else if (coords[1][0] == coords[0][0] && coords[2][0] == coords[0][0]) {
        if (coords[1][1] + coords[0][1] + coords[2][1] == coords[0][0]) {
            ok = true;
        }
    }
    if (coords[1][1] + coords[2][1] == coords[0][1]) {
        if (coords[1][0] +  coords[0][0] == coords[0][1] && coords[1][0] == coords[2][0]) {
            ok = true;
        }
    }   else if (coords[1][1] == coords[0][1] && coords[2][1] == coords[0][1]) {
        if (coords[1][0] + coords[0][0] + coords[2][0] == coords[0][1]) {
            ok = true;
        }
    }
    if (ok) { std::cout << "YES" << "\n"; }
    else { std::cout << "NO" << "\n"; }
}

int main() {
    std::cin.tie(0) -> sync_with_stdio(0);
    int T; std::cin >> T; while(T--) { solve(); }
}