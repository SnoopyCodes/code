#include <bits/stdc++.h>

#define long int64_t

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) {
        long a, b, c, d; cin >> a >> b >> c >> d;
        if (a > c || b > d) { cout << -1 << "\n"; continue; }
        if (a == c && b == d) { cout << 0 << "\n"; continue; }
        //okay it is mathematics time, apparently
        //we first want a set way to even get there
        //when is it possible
        //lets try for partials first i guess
        //3-4: bitmasking is OK
        //a, b, c, d <= 1e6: some sort of dp, i assume
        //wait the key is it corresponds to some sort of combination
        //of the original a and b
        //so we have to solve for ax1 + by1 = c, and ax2 + by2 = d
        //consider the case right before we solve
        //the first pile = c, and the second = d - cx = d % c
        //somehow i feel like we're deriving the extended euclidean (i haven't learned it)
        //and thus, repeat
        //run this process on 5 3 8 19
        //5 3 8 3 is our target (+2)
        //and we just add to do the thing
        //we have to stop when a sum == one, and the other == the other

        //fails on 1 2 3 4 :skull:
        //maybe we missed case where they can suddenly be equal?
        //impossible
        //divisible?
        //2 2 8 12
        //2 4, 2, 6
        //wait i forgor to test tc 2 :skull:
        if (c == d) { cout << -1 << "\n"; continue; }
        if (d < c) { swap(a, b); swap(c, d); }
        long ans = 0;
        while (a < c && b < d) {
            ans += d / c;
            d %= c;
            swap(a, b);
            swap(c, d);
        }
        if (b == d) { swap(a, b); swap(c, d); }
        if ((d - b) % a == 0 && a == c) {
            cout << ans + (d - b) / a << "\n";
        }   else {
            cout << -1 << "\n";
        }
    }
}