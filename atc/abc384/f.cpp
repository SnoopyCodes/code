#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //split into evens and odds
    //2e7 is likely iterable, sievable? hard
    //for 2e7, we can precompute those values in time
    //thus the only hard part is finding all pair sums quickly
    //a + b is what?
    //quiockly quickly iwhtou ta shadow of a doubt
    //damn it idk
    //1, 2, 12, 16
    //3, 13, 17, 14, 18, 28
    //this does give 3 + 13 + 17 + 14 + 18 + 28 however
    //all pair sums can be distinct and thus i don't think there's a quick way to examine it
    //consider this: between evens and odds, we just directly multiply evens times odds to get the sum
    //of them pairwise?
    //3, 4, 6
    //no wait
    //for odds, multiply by # evens, and evens multiply by # odds
    //then add? yes
    //computable in O(N) time
    //can we query for anything equidistant from some number

}