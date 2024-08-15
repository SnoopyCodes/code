// Source: https://usaco.guide/general/io
 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v;
vector<ll> upadd;
vector<ll> upset;
vector<ll> sums;
int s_N;
int blocki(int i) { return i / s_N; }
void apply(int block) {
	if (upset[block]) {
		for (int i = block * s_N; i < s_N * (block + 1); i++) {
			v[i] = upset[block];
		}
		upset[block] = 0;
	}	else if (upadd[block]) {
		for (int i = block * s_N; i < s_N * (block + 1); i++) {
			v[i] += upadd[block];
		}
		upadd[block] = 0;
	}
}
ll query(int l, int r) {
	int lb = blocki(l);
	int rb = blocki(r);

	apply(lb);
	apply(rb);

	ll ans = 0;
	while (l < s_N * (lb + 1) && l <= r) { ans += v[l]; l++; }
	while (r >= s_N * rb && r >= l) { ans += v[r]; r--; }

	lb++;
	while (lb < rb) { ans += sums[lb]; lb++; }

	return ans;
}
void modadd(int l, int r, int val) {
	int lb = blocki(l);
	int rb = blocki(r);

	apply(lb);
	apply(rb);

	while (l < s_N * (lb + 1) && l <= r) { v[l] += val; l++; sums[lb] += val; }
	while (r >= s_N * rb && r >= l) { v[r] += val; r--; sums[rb] += val; }

	lb++;
	while (lb < rb) {
		if (upset[lb]) { upset[lb] += val; }
		else { upadd[lb] += val; }
		sums[lb] += s_N * val;
		lb++;
	}
}
void modset(int l, int r, int val) {
	int lb = blocki(l);
	int rb = blocki(r);

	apply(lb);
	apply(rb);

	while (l < s_N * (lb + 1) && l <= r) { sums[lb] += val - v[l]; v[l] = val; l++; }
	while (r >= s_N * rb && r >= l) { sums[rb] += val - v[r]; v[r] = val; r--; }
	lb++;
	while (lb < rb) {
		if (upadd[lb]) { upadd[lb] = 0; }
		upset[lb] = val;
		sums[lb] = val * s_N;
		lb++;
	}
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
	int N, Q; cin >> N >> Q;
	v.resize(N);
	s_N = 0;
	while (s_N * s_N < N) { s_N++; }
    s_N = 256; //testing if cache whtatever iframe told me is true
	sums.resize(N / s_N + 1);
	upset.resize(N / s_N + 1);
	upadd.resize(N / s_N + 1);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		sums[blocki(i)] += v[i];
	}
	for (int q = 0; q < Q; q++) {
		int t; cin >> t;
		if (t == 3) {
			int l, r; cin >> l >> r; l--; r--;
			cout << query(l, r) << "\n";
		}	else if (t == 2) {
			int a, b, x; cin >> a >> b >> x; a--; b--;
			modset(a, b, x);
		}	else {
			int a, b, x; cin >> a >> b >> x; a--; b--;
			modadd(a, b, x);
		}
	}
}