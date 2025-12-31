#include <bits/stdc++.h>

using namespace std;

const int  MOD = 998244353;
#define int long long
template<int z> using ii = array<int , z>;
template<class T> using vt = vector<T>;
#define add push_back
#define rep(i,a,b) for(auto i=a; i<(b); i++)

//FIND RIGHTMOST INDEX IN UNIMODAL MAXIMAL ARRAY == MAXIMUM

// ----------------- First Implementation -----------------

int exp(int x, int p = MOD - 2) {
	int res = 1;
	while (p > 0) {
		if (p % 2 & 1) { (res *= x) %= MOD; }
		(x *= x) %= MOD;
		p /= 2;
	}
	return res;
}

vector<int> fac, ifac;

int choose(int n, int r) {
    return n < r ? 0 : fac[n] * ifac[r] % MOD * ifac[n - r] % MOD;
}
void prec(int n) {
	fac.resize(n + 1);
	ifac.resize(n + 1);
	fac[0] = 1;
    for (int i = 1; i <= n; i++) {
		fac[i] = fac[i-1] * i % MOD;
	}
	ifac[n] = exp(fac[n]);
	for (int i = n - 1; i > -1; i--) {
		ifac[i] = ifac[i + 1] * (i + 1) % MOD;
	}
}

vt<int> p2;


void solve() {
    //we only ever match a[i] to one particular group. find that group.
    ii<61> a{};
    int n; cin >> n;
    int x; cin >> x;
    int total = n;

    rep(i, 0, n) {
        int y; cin >> y;
        a[y]++;
    }

    int ans = 0;
    int amt = 0; //bits already set
    int seen_bits = 0;
    int prev_bit = 61;
    int prev_ways = 1;
    
    for (int i = 60; i > -1; i--) {
        if (x >> i & 1) {
            int cnt = 1;
            for (int j = i - 1; j > -1; j--) {
                if (x >> j & 1) {
                    cnt++;
                }   else {
                    break;
                }
            }

            //the given bit is i + amt
            int b = i + amt;
            //how many reindeer are in between b and prev_bit?
            int sum = 0;
            rep(j, b + 1, prev_bit) {
                sum += a[j];
            }
            //ans += 2^(sum - 1) * 2^(N - sum - amt)
            //surely?
            if (sum > 0) {
                (ans += prev_ways * (p2[sum] - 1) % MOD * p2[total - sum - seen_bits] % MOD) %= MOD;
            }
            //new ways := C(a[i], cnt) * prev_ways
            if (a[b] < cnt) {
                prev_ways = 0;
                break;
            }
            int new_ways = choose(a[b], cnt) * prev_ways % MOD;
            //now count overfill (choosing > cnt from this)
            //at least one
            //wait im selling it was hockey stick?
            //C(a[b], cnt + 1), C(a[b], cnt + 2), ...
            //
            if (a[b] > cnt) {
                int ways_to_not = 0;
                rep(j, 0, cnt + 1) {
                    (ways_to_not += choose(a[b], j) % MOD) %= MOD;
                }
                int ways_to_over = (p2[a[b]] - ways_to_not + MOD) % MOD;
                //p2[a[b] - cnt] is # of ways to turn other stuff on?
                (ans += prev_ways * ways_to_over % MOD * p2[total - sum - seen_bits - a[b]] % MOD) %= MOD;
            }

            amt += cnt;
            seen_bits += a[b];
            seen_bits += sum;
            prev_bit = b;
            prev_ways = new_ways;

            i = i - cnt + 1;
        }
    }

    int sum = 0;
    rep(i, 0, prev_bit) {
        sum += a[i];
    }
    (ans += p2[sum] * prev_ways % MOD) %= MOD;
    cout << ans << "\n";

}


// ----------------- Second Implementation -----------------
//brute force

void solve2() {
    int n; cin >> n;
    int x; cin >> x;

    vt<int> a;
    rep(i, 0, n) {
        int y; cin >> y;
        a.add(y);
    }


    vt<ii<62>> dp(n + 1, ii<62>{});
    rep(i, 0, n + 1) rep(j, 0, 62) dp[i][j] = 0;
    int numb = __builtin_popcountll(x);
    vt<int> pos;
    for (int i = 61; i > -1; i--) {
        if (x >> i & 1) {
            pos.add(i);
            // cout << i << "\n";
        }
    }
    dp[0][0] = 1;
    rep(i, 0, n) {
        
        rep(j, 0, numb) {
            int cur = a[i] - j;
 
            (dp[i + 1][j] += dp[i][j]) %= MOD;
            if (cur == pos[j]) {
                (dp[i + 1][j + 1] += dp[i][j]) %= MOD;
            }   else if (cur > pos[j]) {
                //
                (dp[i + 1][numb] += dp[i][j]) %= MOD;
            }
        }
        (dp[i + 1][numb] += dp[i][numb] * 2) %= MOD; //we can always choose to include this one or not
    }
 
    cout << dp[n][numb] << "\n";
}

// ----------------- Test Case Generator -----------------
string generateTestCase() {
    //write to oss
    //MODIFY
    ostringstream oss;
    // cout << "GENERATING" << endl;
    //use maxbit 20
    int x = 0;
    for (int i = 5; i > -1; i--) {
        if (rand() & 1) {
            x += 1 << i;
        }
    }
    ii<21> amt{};
    int sum = 0;
    for (int i = 5; i > 0; i--) {
        //choose any number between 0 and 10 to have
        amt[i] = rand() % 4;
        sum += amt[i];
    }
    oss << sum << "\n";
    oss << x << "\n";

    for (int i = 20; i > 0; i--) {
        rep(j, 0, amt[i]) {
            oss << i << " ";
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
signed main() {
    srand(time(NULL));

    ii<61> cnt{};
    p2.resize(6e5);
    prec(6e5);
    p2[0] = 1;
    rep(i, 1, 6e5) p2[i] = p2[i-1] * 2 % MOD;
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
