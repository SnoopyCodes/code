#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //first: is modulo associative?
    //17 mod 7 mod 3 = 0
    //17 mod 3 mod 7 = 2
    //no
    //also, if we ever make
    //any a[i] < b[i], it is cooked!
    //so something that constructs a sequence
    //is iterating through which ones will
    //
    //wait
    //i think we should go from largest modulos to small ones
    //this much is obvious
    //8 cannot become 5. why is that?
    //bc (8-5) < (5+1)
    //we can try to start from the least cost
    //starting from 0 and going to 50
    //
}