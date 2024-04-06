#include <bits/stdc++.h>
#define ll long long

using namespace std;
bool sim(long long x, ll N, ll M, ll K) {
    long long days = 0;
    while (N > 0 && days <= K) {
        days++;
        long long give = N / x;
        if (give > M) { N -= give; }
        else { N -= M; }
    }
    return N <= 0 && days <= K;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("loan.in", "r", stdin);
    freopen("loan.out", "w", stdout);
    long long N, K, M;
    cin >> N >> K >> M;
    if (K <= 10e6) {
        long long s = 0, e = K;
        while (e - s > 1) {
            long long m = (s + e + 1) / 2;
            if (sim(m, N, M, K)) {
                s = m;  //linear search ends too early-- ikd how to do this
            }   else {
                e = m;
            }
        }
        cout << s; return 0;
    } else {
        int i = 1;
        while (sim(i, N, M, K)) { i++; }
        i--;
        cout << i;
    }
    //if K <= 10^6 i think binary searching and stuff is viable
    //but if its greater then just linear search lolloloolol
    //so fj has infinite milk
    //oh nvm they constrained it lmao
    //bad bad bad reading comprehension
    //okay so what do we do
    //try and make X * K = N ?
    //it is allowed to make partials for cases 2-4, netting 3 / 10
    //but when past that then what?
    //for day i, the total given is given(i-1) + (N - given(i-1)) / X as long as given for this day > M
    //for day 2 given is N / X + (N - (N / X)) / X
    //the upper bound on the search is K itself
    //we cannot possibly attempt to simulate all K days.
    //this is a theoretical sqrt (K) problem.
    //do the factors of N in any way relate to solving the problem?
}