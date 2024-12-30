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
    HashedString hs("abc");
    cout << hs.get_hash(0, 2) << "\n";
}