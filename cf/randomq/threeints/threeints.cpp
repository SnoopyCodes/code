#include <bits/stdc++.h>

using namespace std;
void solve() {
    int a, b, c; cin >> a >> b >> c;
    //main bottleneck is c being a multiple of b, probably
    //so basically move b down until it works?
    //but then we need to check on c
    //maybe bs on number of operations
    //okay and then what
    //even if we bs
    //we need to see if we can get something within a minimum number of operations
    //or we could yk iterate through possible values of a
    //but then going through for b is probably root n
    //iterate through the possible multiples that each will be of
    //or of just b i think
    //i feel like just doing 1 to 1e4 checking on multiples works though
    //if we do this 
    //wait if we just iterate through values of a
    //then what
    //we can choose values of b but how
    //not binary search surely
    //wait brute force is devious
    int small = INT_MAX;
    int na, nb, nc;
    for (int i = 1; i <= 2 * a; i++) {
        for (int j = 1; j * i <= 2 * b; j++) {
            if (j > c) { break; }
            int nearest = min(abs(c - i * j * (c / (i * j))), abs(i * j * (c / (i * j)+ 1) - c));
            int x = abs(a - i) + abs(b - i * j) + nearest;
            if (small > x) {
                small = x;
                na = i, nb = i * j, nc = abs(c - i * j * (c / (i * j))) < abs(i * j * (c / (i * j)+ 1) - c) ? i * j * (c / (i * j)) : i * j * (c / (i * j)+ 1);
            }
        }
    }
    cout << small << "\n";
    cout << na << " " << nb << " " << nc << "\n";
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T) { T--; solve(); }
}