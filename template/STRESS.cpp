#include <bits/stdc++.h>

#define long int64_t
#define vec vector
#define arr array
#define rsz resize
const int INF = 1e9;
const long INFL = 4e18;


using namespace std;
// ----------------- First Implementation -----------------


void solve() {
    //MODIFY
    //run as normal, without multitest
}

// ----------------- Second Implementation -----------------
//brute force
void solve2() {
    //MODIFY
    int N, Q; cin >> N >> Q;
    vec<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int q = 0; q < Q; q++) {
        int rooms, l, r; cin >> rooms >> l >> r; l--;
        int ans = -1;
        for (int i = l; i < r; i++) {
            if (A[i] >= rooms) { ans = i; break; }
        }
        cout << ans + 1 << " ";
        if (ans > -1) { A[ans] -= rooms; }
    }
    cout << "\n";
}
 
// ----------------- Test Case Generator -----------------
string generateTestCase() {
    //write to oss
    //MODIFY
    ostringstream oss;
    int n = 1000;
    int q = 1000;
    oss << n << " " << q << "\n";
    for (int i = 0; i < n; i++) {
        int w = rand() % 10 + 1;
        oss << w << (i == n - 1 ? "\n" : " ");
    }
    for (int i = 0; i < q; i++) {
        int x = rand() % 5 + 1;
        int l = rand() % n + 1;
        int r = rand() % n + 1;
        if (l > r) { swap(l, r); }
        oss << x << " ";
        oss << l << " ";
        oss << r << " ";
        oss << "\n";
    }
    return oss.str();
}
 
// ----------------- Helpers to Run a Solve Function -----------------
string runSolve(function<void()> solveFunc, const string &testInput) {
    // Save the original stream buffers.
    streambuf* origCin  = cin.rdbuf();
    streambuf* origCout = cout.rdbuf();
 
    // Redirect cin and cout.
    istringstream iss(testInput);
    ostringstream oss;
    cin.rdbuf(iss.rdbuf());
    cout.rdbuf(oss.rdbuf());
 
    // Run the provided solve function.
    solveFunc();
 
    // Restore original stream buffers.
    cin.rdbuf(origCin);
    cout.rdbuf(origCout);
 
    return oss.str();
}
 
// ----------------- Main Stress-Testing Loop -----------------
int main() {
    srand(time(NULL));
    //MODIFY
    int stressTests = 10;
    for (int i = 1; i <= stressTests; i++) {
        string test = generateTestCase();
        string out1 = runSolve(solve, test);
        string out2 = runSolve(solve2, test);
        if (out1 != out2) {
            cout << "Mismatch found on test case #" << i << ":\n";
            cout << "Test case input:\n" << test << "\n";
            cout << "Output from solve:\n" << out1 << "\n";
            cout << "Output should be:\n" << out2 << "\n";
            return 0;
        }
    }
    cout << "All stress tests passed.\n";
    return 0;
}
