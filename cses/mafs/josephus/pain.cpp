#include <bits/stdc++.h>

using namespace std;
int remove(int N, bool prev) {
    int remove;
    if (prev) {
        if (N % 2 == 1) {
            prev = false;
            remove = N / 2 + 1;
        }   else {
            remove = N / 2;
        }
    }   else {
        remove = N / 2;
        if (N % 2 == 1) {
            prev = true;
        }
    }
    return remove;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int Q; cin >> Q;
    for (int q = 0; q < Q; q++) {
        int N, K; cin >> N >> K;
        //so we should declare a parity thing 
        //is there a way to work backwards?
        //find at which level it is at
        bool first = false; //if we are removing the first this iteration
        int dist = 1;
        int one = 1;
        //how do we figure out if its able ot be selected this iteration?
        while (K > remove(N, first) && N > 1) {
            //what to do with tmp?
            //if prev is false then remove normally-- N / 2
            //otherwise remove N / 2 - 1 if N is now odd?
            //it's known that they have to be equidistant from each other lmao
            //so we can keep the first number in the sequence
            //then go based on that
            dist *= 2;
            int remove;
            if (first) {
                one += dist / 2;  //this should work
                if (N % 2 == 1) {
                    first = false;  //next iteration it does not need removal
                    remove = N / 2 + 1;
                }   else {
                    remove = N / 2;
                }
            }   else {
                remove = N / 2;
                if (N % 2 == 1) {
                    first = true;
                }
            }
            K -= remove;
            N -= remove;
        }
        if (N == K) {
            cout << one << "\n";
        }   else if (first) {
            cout << one + (K - 1) * dist * 2 << "\n";
        }   else {
            cout << one + dist + (K - 1) * dist * 2 << "\n";
        }
    }
}