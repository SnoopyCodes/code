#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> v;
vector<ll> upadd;
vector<ll> upset;
vector<ll> sum;
const int sz = 256;

void apply(int b) {
	if (upset[b]) {
		for (int i = b * sz; i < sz * (b + 1); i++) { v[i] = upset[b]; }
		upset[b] = 0;
	}	else if (upadd[b]) {
		for (int i = b * sz; i < sz * (b + 1); i++) { v[i] += upadd[b]; }
		upadd[b] = 0;
	}
}
ll query(int l, int r) {
 
	apply(l/sz);
	apply(l/sz);
 
	ll ans = 0;
	while (l < sz * (l/sz + 1) && l <= r) { ans += v[l]; l++; }
	while (r >= sz * r/sz && r >= l) { ans += v[r]; r--; }
 
	lb++;
	while (lb < rb) { ans += sum[lb]; lb++; }
 
	return ans;
}
void modadd(int l, int r, int val) {
	int lb = blocki(l);
	int rb = blocki(r);
 
	apply(lb);
	apply(rb);
 
	while (l < sz * (lb + 1) && l <= r) { v[l] += val; l++; sum[lb] += val; }
	while (r >= sz * rb && r >= l) { v[r] += val; r--; sum[rb] += val; }
 
	lb++;
	while (lb < rb) {
		if (upset[lb]) { upset[lb] += val; }
		else { upadd[lb] += val; }
		sum[lb] += sz * val;
		lb++;
	}
}
void modset(int l, int r, int val) {
	int lb = blocki(l);
	int rb = blocki(r);
 
	apply(lb);
	apply(rb);
 
	while (l < sz * (lb + 1) && l <= r) { sum[lb] += val - v[l]; v[l] = val; l++; }
	while (r >= sz * rb && r >= l) { sum[rb] += val - v[r]; v[r] = val; r--; }
	lb++;
	while (lb < rb) {
		if (upadd[lb]) { upadd[lb] = 0; }
		upset[lb] = val;
		sum[lb] = val * sz;
		lb++;
	}
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
	int N, Q; cin >> N >> Q;
	v.resize(N);
	sum.resize(N / sz + 1);
	upset.resize(N / sz + 1);
	upadd.resize(N / sz + 1);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		sum[i/sz] += v[i];
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