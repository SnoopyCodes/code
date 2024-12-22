#include <bits/stdc++.h>
#define long int64_t
using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    long S; cin >> S;
    vector<int> A(N);
    long total = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        total += A[i];
    }
    //run modulo on the sum over the whole sum of the array
    bool over = S >= total;
    S %= total;
    long bruh = total;
    //now we only need to find if a pf sum and sf sum exist that sum to it
    set<long> pf;
    total = 0;
    for (int i = 0; i < N; i++) {
        pf.insert(total);
        total += A[i];
        if (total == S) { cout << "Yes" << "\n"; return 0; }
    }
    total = 0;
    for (int i = N - 1; i > -1; i--) {
        //make sure to cover all cases
        //just check if this S - sf is in set
        total += A[i];
        long comp = S - total;
        if (comp < 0 && over) { comp += bruh; }
        if (pf.count(comp)) { cout << "Yes" << "\n"; return 0; }
    }
    cout << "No" << "\n";
    
}