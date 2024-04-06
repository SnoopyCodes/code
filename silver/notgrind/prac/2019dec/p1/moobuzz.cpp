#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("moobuzz.in", "r", stdin);
    freopen("moobuzz.out", "w", stdout);
    int N; cin >> N;
    //can we freely find the multiple of 15?
    //for each 15 there will be 8 left over? seems like it
    int rem = N % 8;
    N /= 8;
    N *= 15;
    if (rem == 0) { rem = -1; }
    if (rem < 3) { N += rem; }
    if (rem == 3) { N += 4; }
    if (rem == 4) { N += 7; }
    if (rem == 5) { N += 8; }
    if (rem == 6) { N += 11; }
    if (rem == 7) { N += 13; }
    //okay time to do math then
    //is k = a - floor(a/3) - floor(a/5) + floor(a/15)
    //if we have an integer k then k = x - floor[x/5]
    //x = y - floor[y/3];
    cout << N;
}