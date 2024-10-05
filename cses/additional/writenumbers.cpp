#include <bits/stdc++.h>

using namespace std;
long long count(long long g) {
    long long strip = 0, mult = 1, ans = 0;
    while (g > 0) {
        //100, 10, 1
        //10 times units digit
        //then it just counts 10?
        //
        int dig = g % 10;
        g /= 10;
        ans += g * mult;
        //now check strip
        if (dig == 1) {
            ans += strip + 1;
        }   else if (dig > 1) {
            ans += mult;
        }

        strip += mult * dig;
        mult *= 10;
    }
    return ans;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //recommended by draid
    //obviously, this is bounded by the number of 1's we are writing
    //therefore, we need to count the number of 1's
    //this leads to considering the units digits 1-9, 10-99
    //we find the formula for # of 1's written in each group as 
    //f(x) = f(x-1) * 9 + 10^x
    //also, as hinted by draid, we can perform binary search
    //but we need to find the number of 1's
    //
    //a bit of struglging later
    //find for every single digit how many times it appears, right
    //num before it
    //eg 54 1 appears in units digit 5 + 1 times (4 > 0)
    //244: in tens place, appears 2 * 10 times cause before it is 10
    //but then add 10 more times cuz 4 > 0
    //and in hundreds place, appears 100 times
    //144: hundreds place appears 

    long long N; cin >> N;
    long long s = 0, e = LONG_LONG_MAX / 2;  //i have no idea what the bound is
    while (s + 1 < e) {
        long long m = s + (e - s) / 2;
        //find number of 1's :sob:
        if (count(m) <= N) { s = m; }
        else { e = m; }
    }
    cout << s << "\n";
}