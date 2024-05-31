#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    //uh bruh what
    //i suspect we will double count and eventually divide by 2
    int target = (N * (N + 1)) / 2;
    if (target % 2) { cout << 0; return 0; }
    target <<= 1; //i love arrows
    //wait just 
}