#include <bits/stdc++.h>

using namespace std;

#define long long long
const int BIG = 1e9 + 1;
const long INF = 4e18 + 1000;
#define int long
#define tp template
tp<int z> using ints = std::array<int, z>;
tp<int z> using longs = std::array<long, z>;

tp<class T> using vt = vector<T>;
tp<class T> using vv = vt<vt<T>>;


// ----------------- First Implementation -----------------

void solve() {
    int N; std::cin >> N;
    vt<int> A(N);
    vv<int> msb(32);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
        for (int b = 31; b > -1; b--) {
            if (A[i] & 1 << b) {
                msb[b].push_back(i);
                break;
            }
        }
    }

    long ans = 0;

    for (int b = 0; b < 4; b++) {
        vt<int> pf(N), sf(N);
        vt<bool> pfst(N), sfst(N);
        bool cur = false;
        for (int i = 0; i < N; i++) {
            cur ^= bool(A[i] & 1 << b);
            pf[i] += cur;
            pfst[i] = cur;
            if (i < N - 1) { pf[i + 1] = pf[i]; }
        }
        cur = false;
        for (int i = N - 1; i > -1; i--) {
            cur ^= bool(A[i] & 1 << b);
            sf[i] += cur;
            sfst[i] = cur;
            if (i > 0) { sf[i - 1] = sf[i]; }
        }
        for (int i : msb[b]) {
            /*
            oh my god okay
            get right side
            the xor of the two ranges not including i should be odd parity
            we want empty range
            */
            int odd_more = pf[N - 1] - pf[i];
            int even_more = N - i - 1 - odd_more;
            if (pfst[i]) { std::swap(odd_more, even_more); }
            even_more++;
            int odd_less = sf[0] - sf[i];
            int even_less = i - odd_less;
            if (sfst[i]) { std::swap(odd_less, even_less); }
            even_less++;
            // std::cout << odd_more << " " << even_more << " " << odd_less << " " << even_less << "\n";
            ans += (long) odd_more * even_less + (long) even_more * odd_less;
        }
    }
    std::cout << ans << "\n";
    
}

// ----------------- Second Implementation -----------------
//brute force

void solve2() {
    std::cout << 83338333349998 << "\n";
    
}
 
// ----------------- Test Case Generator -----------------
string generateTestCase() {
    //write to oss
    //MODIFY
    ostringstream oss;
    // cout << "GENERATING" << endl;
    int N = 100000;
    oss << N << endl;
    for (int i = 0; i < N; i++) {
        oss << 1 << " \n"[i == N - 1];
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
    int stressTests = 1;
    for (int i = 1; i <= stressTests; i++) {
        string test = generateTestCase();
        // cout << test << endl;
        string out2 = runSolve(solve2, test);
        // cout << ".." << endl;
        string out1 = runSolve(solve, test);
        // cout << "." << endl;
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
