#include <bits/stdc++.h>

using namespace std;

#define int long long
const int  MOD = 1e9 + 7;
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;
#define add push_back

// ----------------- First Implementation -----------------

void solve() {
    string s; cin >> s;
    int N = s.size();
    int dp[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = N;
        }
    }
    for (int i = 0; i < N; i++) dp[i][i] = 0;
    for (int i = 0; i < N - 1; i++) if (s[i] == s[i + 1]) dp[i][i + 1] = 0;
    for (int len = 1; len < N; len++) {
        for (int i = 0; i <= N - len; i++) {
            int j = i + len - 1;
            if (i) {
                dp[i-1][j] = min(dp[i][j] + 1, dp[i-1][j]);
            }
            if (j < N - 1) {
                dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
            }
            if (i && j < N - 1 && s[i-1] == s[j+1]) {
                dp[i-1][j+1] = min(dp[i-1][j+1], dp[i][j]);
            }
        }
    }
    cout << dp[0][N-1] << "\n";
}

// ----------------- Second Implementation -----------------
//brute force

void solve2() {
    string s; cin >> s;
    int n = s.size();
    int dp[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dp[i][j] = 0;
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[0][n-1] << "\n";

}

//from https://github.com/eysbutno/use-a-cow/blob/main/Implementation/StresstestingFunctions.cpp
inline namespace Random {
    mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

    template<typename T> T random() {
        T MAX_VAL = numeric_limits<T>::max();
        return uniform_int_distribution<T>(0, MAX_VAL)(rng);
    }

    template<typename T> T random(T bound) {
        return uniform_int_distribution<T>(0, bound)(rng);
    }

    template<typename T> T random(T l, T r) {
        return uniform_int_distribution<T>(l, r)(rng);
    }

    template<typename T> void rand_shuffle(T l, T r) {
        shuffle(l, r, rng);
    }
}

/**
 * Returns a random tree that should be pretty random.
 */
vector<array<int, 2>> gen_tree(int n) {
    vector<array<int, 2>> edges(n - 1);
    vector<int> ord(n);
    iota(begin(ord), end(ord), 0);
    rand_shuffle(begin(ord), end(ord));
    for (int i = 1; i < n; i++) {
        int p = ord[random(i - 1)];
        edges[i - 1] = {min(p, ord[i]), max(p, ord[i])};
    }
    return edges;
}

/**
 * Retrurns a random undirected graph. Note that
 * multiedges and edges that don't connect two nodes
 * aren't allowed.
 */
vector<array<int, 2>> gen_graph(int n, int m) {
    set<array<int, 2>> edges;
    while (edges.size() < m) {
        int a = random(n - 1), b = random(n - 1);
        if (a > b) swap(a, b);
        if (a != b && !edges.count({a, b})) {
            edges.insert({a, b});
        }
    }
    return vector<array<int, 2>>(begin(edges), end(edges));
}

/** 
 * Same as gen_graph, but the graph needs to be connected.
 */
vector<array<int, 2>> gen_con_graph(int n, int m) {
    assert(m >= n - 1);
    assert(m <= n * (n - 1) / 2);
    auto res = gen_tree(n);
    set<array<int, 2>> added(begin(res), end(res));
    while (m > n - 1) {
        int u = random(n - 1) % n, v = random(n - 1) % n;
        if (u > v) { swap(u, v); }
        if (u != v && !added.count({u, v})) {
            m--;
            added.insert({u, v});
            res.push_back({u, v});
        }
    }
    return vector<array<int, 2>>(begin(res), end(res));
}

vector<array<int, 2>> gen_rand_graph(int n, int m) {
    vector<array<int, 2>> res(m);
    for (int i = 0; i < m; i++) {
        do {
            res[i] = {random(n - 1), random(n - 1)};
        } while (res[i][0] == res[i][1]);
    }
    return res;
}


/**
 * Returns a random array with values being on [low, high]
 */
template <typename T> vector<T> gen_arr(int n, T low, T high) {
    int diff = (int) (high - low);
    vector<T> res(n);
    for (int i = 0; i < n; i++) {
        res[i] = random(low, high);
    }
    return res;
}

// ----------------- Test Case Generator -----------------
string generateTestCase() {
    //write to oss
    //MODIFY
    ostringstream oss;
    int n = random(5, 10);
    string s = "";
    for (int i = 0; i < n; i++) {
        char c = random('a', 'z');
        s += c;
    }
    oss << s;

    oss << "\n";


    // cout << oss.str() << endl;
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
signed main() {
    srand(time(NULL));

    //MODIFY
    int stressTests = 1000;
    for (int i = 1; i <= stressTests; i++) {
        // cout << "making test" << endl;
        string test = generateTestCase();
        // cout << "run s2" << endl;
        string out2 = runSolve(solve2, test);
        // cout << "run s" << endl;
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
