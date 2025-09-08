#include <bits/stdc++.h>
#define long int64_t
using namespace std;

const int MOD = 1e9 + 7;

long exp(long x, int p) {
	long res = 1;
	while (p > 0) {
		if (p % 2 & 1) { res = res * x % MOD; }
		x = x * x % MOD;
		p /= 2;
	}
	return res;
}

int main() {
	freopen("help.in", "r", stdin);
	freopen("help.out", "w", stdout);
	int N; cin >> N;
	vector<int> interval(2 * N);
	long ans = 0;
	for (int i = 0; i < N; i++) {
		int l, r; cin >> l >> r; l--; r--;
		interval[l]++;
		interval[r]--;
	}
	//find the contribution of each one as a left bound
	//set some segments to be active
	//all l, r are distinct
	//simply count a single segment's contributions
	//as a left bound
	//so how many cover this one
	int can = N;
	for (int i = 2 * N - 1; i > -1; i--) {
		if (interval[i] > 0) {
			(ans = (ans + exp(2, can))) %= MOD;
		}
		can += interval[i];
	}
	cout << ans << "\n";
	
}