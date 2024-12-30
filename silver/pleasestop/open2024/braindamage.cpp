#include <bits/stdc++.h>
#define long int64_t
using namespace std;

class HashedString {
  private:
	// change M and B if you want
	static const long M = 1e9 + 9;
	static const long B = 9973;

	// pow[i] contains B^i % M
	static vector<long> pow;

	// p_hash[i] is the hash of the first i characters of the given string
	vector<long> p_hash;

  public:
	HashedString(const string &s) : p_hash(s.size() + 1) {
		while (pow.size() <= s.size()) { pow.push_back((pow.back() * B) % M); }

		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
		}
	}

	long get_hash(int start, int end) {
		long raw_val = (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
		return (raw_val % M + M) % M;
	}
};
vector<long> HashedString::pow = {1};



int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    string str; cin >> str;
    //well i don't wanna learn hashing
    vector<vector<int>> sz(N + 1, vector<int>(N + 1));
    for (int K = 1; K <= N; K++) {
        for (int L = 1; L <= K; L++) {
            sz[K][L] = N - K + 1;
        }
    }
    HashedString hs(str);
    vector<int> ans(N + 1);
    for (int L = 1; L <= N; L++) {
        //hopefully N^3 and fractional
        vector<int> strings;
        for (int i = 0; i <= N - L; i++) {
            strings.push_back(i);
        }
        auto cmp = [&](int i, int j) {
            int s = 0, e = L + 1;
            //let s be length of lcp
            while (s + 1 < e) {
                int m = (s + e) / 2;
                if (hs.get_hash(i, i + m - 1) == hs.get_hash(j, j + m - 1)) { s = m; }
                else { e = m; }
            }
            if (s == L) { return i < j; }
            return str[i + s] < str[j + s];
        };
        sort(strings.begin(), strings.end(), cmp);
        // for (int i = 0; i <= N - L; i++) {
        //     cout << strings[i] << " ";
        // }
        // cout << "\n";
        // cout << "\n";
        set<int> s;
        for (int i = 0; i <= N - L; i++) {
            //OK, what does this apply to?
            //for some K
            int j = strings[i];
            // cout << strings[i].first << "\n";
            int llim = -1, rlim = N;
            if (!s.empty()) {
                if (s.upper_bound(j) != s.begin()) {
                    llim = *(--s.upper_bound(j));
                }
                if (s.upper_bound(j) != s.end()) {
                    rlim = *s.upper_bound(j);
                }
            }
            // cout << llim << " " << rlim << "\n";
            //start bounded at llim, end bounded at rlim, both exclusive
            for (int K = L; K <= N; K++) {
                int start = max(j - (K - L), llim+1);
                int end = min(N - K + 1, min(rlim - (K - L), j + 1));
                if (start >= end) { continue; }
                // cout << start << " " << end << " " << K << " " << L << "\n";
                sz[K][L] -= end - start - 1;
            }
            s.insert(j);
        }
        // cout << "\n";
    }
    // vector<int> ans(N + 1);
    for (int K = 1; K <= N; K++) {
        for (int L = 1; L <= K; L++) {
            ans[sz[K][L]]++;
            // cout << sz[K][L] << " ";
        }
        // cout << "\n";
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }
}