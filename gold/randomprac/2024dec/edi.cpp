#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> lab_idx[N];

// use two pointers to manually calculate number of groups
int get_groups(int label, int x) {
	int cnt = 0, l = 0, r = 0;
	auto &v = lab_idx[label];
	while (l < (int)v.size()) {
		while (r < (int)v.size() && v[r] - v[l] <= x) { r++; }
		cnt++;
		l = r;
	}
	return cnt;
}

int n;
vector<int> nxt;

int get_groups_big(int label, int x) {
	int cnt = 0, i = lab_idx[label][0];
	while (i < n) {
		cnt++;
		if (i + x + 1 >= n) break;
		i = nxt[i + x + 1];
	}
	return cnt;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	nxt.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		lab_idx[c].push_back(i);
	}
	vector<int> small_ans(n + 1), large_ans(n + 1);
	int SQ = (int)sqrt(n);
	for (int label = 1; label <= n; label++) {
		auto& v = lab_idx[label];
		int lab_sz = v.size();
		if (lab_sz > SQ) {
			// Subtask 2
			fill(nxt.begin(), nxt.end(), 0);
			for (int i : v) { nxt[i] = i; }
			nxt[n] = n;
			for (int i = n - 1; i >= 0; i--) {
				if (!nxt[i]) nxt[i] = nxt[i + 1];
			}
			for (int x = 1; x <= n; x++) {
				large_ans[x] += get_groups_big(label, x);
			}
		} else {
			// Subtask 3
			for (int groups = 1; groups <= lab_sz; groups++) {
				int l = 0, r = n + 1;
				while (l < r - 1) {
					int mid = l + (r - l) / 2;
					if (get_groups(label, mid) < groups) {
						r = mid;
					} else {
						l = mid;
					}
				}
				// will contribute to x in the range of [1, r)
				small_ans[1]++;
				if (r <= n) small_ans[r]--;
			}
		}
	}
	for (int i = 2; i <= n; i++) { small_ans[i] += small_ans[i - 1]; }
	for (int i = 1; i <= n; i++) {
		cout << small_ans[i] + large_ans[i] << "\n";
	}
}
