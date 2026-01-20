#include <bits/stdc++.h>

using namespace std;

const int  MOD = 998244353;
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;
#define add push_back
#define rep(i,a,b) for(auto i=a; i<(b); i++)

//FIND RIGHTMOST INDEX IN UNIMODAL MAXIMAL ARRAY == MAXIMUM

// ----------------- First Implementation -----------------

void solve() {
    int N; cin >> N;
    string s; cin >> s;

    vt<int> suff(N + 1, 0), suffplus(N + 1, N);
    for (int i = N - 1; i > -1; i--) {
        suff[i] = suff[i + 1] + (s[i] == ')');
        suffplus[i] = suffplus[i + 1];
        if (s[i] == '(') suffplus[i] = i;
    }

    int ind = -1;
    int ct = 0;
    int ans = 0;
    rep(i, 0, N) {
        if (s[i] == ')') {
            //try to break out
            if (suff[suffplus[i]] >= ct + 1) {
                //we break here
                ind = i;
                break;
            }   else {
                ct--;
                ans++;
            }
        }   else {
            ct++;
            ans++;
        }
    }

    ind++;
    if (suff[ind] < ct || ind == 0) {
        cout << -1 << "\n";
        return;
    }

    rep(i, ind, N) {
        if (s[i] == '(') {
            if (suff[i] >= ct + 1) {
                ans++;
                ct++;
            }
        }   else {
            assert(ct > 0);
            ans++;
            ct--;
        }
    }


    cout << ans << "\n";
}
// ----------------- Second Implementation -----------------
//brute force

void solve2() {
    int N; cin >> N;
    string s; cin >> s;
    int ans = -1;
    rep(mask, 1, 1 << N) {
        string cmp = "";
        rep(i, 0, N) {
            if (mask >> i & 1) {
                cmp += s[i];
            }
        }
        bool k = true;
        int bal = 0;
        rep(i, 0, size(cmp)) {
            bal += cmp[i] == '(' ? 1 : -1;
            if (bal < 0) {
                k = false;
                break;
            }
        }
        if (!k || bal != 0) continue;
        bool better = false;
        rep(i, 0, size(cmp)) {
            if (s[i] != cmp[i]) {
                if (cmp[i] == '(') {
                    better = true;
                    break;
                }   else {
                    break;
                }
            }
        }
        // if (__builtin_popcount(mask) && better) {
        //     cout << cmp << endl;
        // }
        if (better) ans = max(ans, __builtin_popcount(mask));
        
    }
    cout << ans << "\n";
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
    auto res = gen_tree(n);
    set<array<int, 2>> added(begin(res), end(res));
    for (int i = 0; i < m - (n - 1); i++) {
        int u = random(n - 1), v = random(n - 1);
        if (u > v) { swap(u, v); }
        if (u != v && !added.count({u, v})) {
            added.insert({u, v});
            res.push_back({u, v});
        }
    }
    return vector<array<int, 2>>(begin(res), end(res));
}

/**
 * Returns a completely random graph with the only restriction being
 * that the graph can't have edges only involving one node.
 */
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
    int n = (rand() % 5) * 2;
    oss << n << "\n";

    int bal = 0;
    int used = 0;
    rep(i, 0, n) {
        if (bal == 0) {
            oss << '(';
            bal++;
            used++;
        }   else {
            if (used < n / 2 && rand() & 1) {
                oss << '(';
                bal++;
                used++;
            }   else {
                oss << ')';
                bal--;
            }
        }
    }
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
