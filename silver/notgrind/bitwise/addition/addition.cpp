#include <bits/stdc++.h>

using namespace std;
int sum(int a, int b) {
    while (b > 0) {
        int carry = a ^ b;
        a ^= b;
        b = carry << 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int a; cin >> a;
    int b; cin >> b;
    
}