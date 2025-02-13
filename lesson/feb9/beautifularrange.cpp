#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    vector<int> A(N);    
    //im so cooked chat
    //for K = 1 it is trivial
    //for K = 2?
    //1, 3, 2
    //jump up 2, go down 1
    //K = 3?
    //1, 4, 2, 3
    //constructive!
    //N = 10, K = 2?
    //1, 3, 2, 4, 5, 6, 7, 8, 9, 10
    A[0] = 1;
    int inc = K;
    int parity = 1;
    for (int i = 1; i < N; i++) {
        if (!inc) { A[i] = A[i - 1] + 1; }
        else {
            A[i] = A[i - 1] + (parity ? 1 : -1) * inc;
            parity ^= true;
            inc--;
            if (inc == 0 && i + 1 < N) { i++; A[i] = A[i - 1] + K; }
        }
    }
    
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";

    set<int> s;
    for (int i = 0; i < N - 1; i++) {
        s.insert(abs(A[i+1] - A[i]));
    }
    if (s.size() == K) { cout << "OK" << "\n"; }
    else { cout << "NOT OK"; }
}