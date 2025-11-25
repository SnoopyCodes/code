#include <bits/stdc++.h>

using namespace std;

#define long long long
#define add push_back
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
template<int z> using ii = array<int, z>;
template<int z> using ll = array<long, z>;
template<class T> using vt = vector<T>;
template<class T> using mt = vt<vt<T>>;

//FIND RIGHTMOST INDEX IN UNIMODAL MAXIMAL ARRAY == MAXIMUM

// ----------------- First Implementation -----------------

void solve() {
    int N; cin >> N;
    vt<int> A(N);
    for (int &u : A) { cin >> u; }
    int s = 0, e = N - 1;
    while (s < e) {
        int m = (s + e) / 2;
        if (A.at(m) <= A.at(m + 1)) { s = m + 1; }
        else { e = m; }
    }
    cout << s << "\n";
}


// ----------------- Second Implementation -----------------
//brute force

void solve2() {
    int N; cin >> N;
    vt<int> A(N);
    for (int &u : A) { cin >> u; }
    for (int i = N - 1; i > -1; i--) {
        if (i == 0 || A[i - 1] < A[i]) { cout << i << "\n"; return; }
    }
}
 
// ----------------- Test Case Generator -----------------
string generateTestCase() {
    //write to oss
    //MODIFY
    ostringstream oss;
    // cout << "GENERATING" << endl;
    int N = 10;
    oss << N << "\n";
    int pk = rand() % N;
    int pkv = 10;
    int curv = 0;
    vt<int> a;
    for (int i = 0; i < N; i++) {
        //choose a random integer in [curv, pkv]
        if (i < pk) {
            int v = curv + rand() % (pkv - curv + 1);
            curv = v;
            a.add(v);
            oss << v;
        }   else if (i > pk) {
            //[curv, 0]
            int v = curv - rand() % (curv + 1);
            curv = v;
            a.add(v);
            oss << v;
        }   else {
            a.add(pkv);
            oss << pkv;
        }
        oss << " ";
    }
    for (int i = 0; i < N - 1; i++) {
        if (i < pk) {
            assert(a[i] <= a[i + 1]);
        }   else {
            assert(a[i] >= a[i + 1]);
        }
    }
    oss << "\n";
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
    int stressTests = 10000;
    for (int i = 1; i <= stressTests; i++) {
        string test = generateTestCase();
        string out2 = runSolve(solve2, test);
        string out1 = runSolve(solve, test);
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
