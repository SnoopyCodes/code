#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll R, G, B; cin >> R >> G >> B;
    //is htis easily mathable?
    //even dp of sorts wouldn't work here
    if (B > G) { swap(B, G); }
    if (R < G) { swap(R, G); }
    if (G < B) { swap(B, G); }
    //R >= G >= B
    //our goal is to equalize G and B first
    //we can only use it up at a 2 : 1 rate
    //now otherwise print R? nope
    //uhhh 
    //so R is good
    //we have the RIGHT to the absolute lowest
    //do we just use up lowest and then do what we can with the rest? i think so
    //okay damn it
    //i think its ll?
    // can we even have more than 
    //2e9, 2e9, 2e9
    //is it just 2e9?
    //i d k
    //6 3 3
    //
    if (2 * (B + G) <= R) {
        cout << B + G << "\n"; return 0;
    }
    //what are the other cases?
    //when does this strategy work?
    //if G is closer to R than to B?
    //hlp
    cout << (B + G + R) / 3 << "\n";
}