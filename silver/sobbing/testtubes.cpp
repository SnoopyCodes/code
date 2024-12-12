#include <bits/stdc++.h>

using namespace std;

void put(bool val, vector<bool> &v) {
	if (v.empty() || val != v.back()) { v.push_back(val); }
}

void solve() {
	int N, P; cin >> N >> P;
	vector<bool> one, two;
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		put(c == '2', one);
	}
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		put(c == '2', two);
	}
    vector<bool> o1 = one, o2 = two;
	vector<array<int, 2>> moves;

	vector<bool> three;
	bool change = false;
    if (one.back() == two.back()) {}
	if (one[0] == two[0] && one.back() == one[0] || two.size() == 1) { change = true; swap(one, two); }
	bool bot = one[0];
    //x, y are sizes
    //we do x - 1 + y - 1 moves i think? + 2
    //when do we not need to do one of these moves?
    //we do them when bottoms are the same
    //
	while (one.size() > 1) {
		bool val = one.back(); one.pop_back();
		if (val == bot) { moves.push_back({1, 2}); put(val, two); }
		else { moves.push_back({1, 3}); put(val, three); }
	}

	while (two.size() > 1) {
		bool val = two.back(); two.pop_back();
		if (val == bot) { moves.push_back({2, 1}); }
		else { moves.push_back({2, 3}); put(val, three); }
	}

	if (one[0] == two[0]) { moves.push_back({2, 1}); two.pop_back(); }
	if (three.size()) {
		moves.push_back({3, 2});
	}

	cout << moves.size() << "\n";
	if (P != 1) {
		for (auto [x, y] : moves) {
			if (change) {
                if (x != 3) { x = 3 - x; }
                if (y != 3) { y = 3 - y; }
			}
			cout << x << " " << y << "\n";
		}
	}
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
	int T; cin >> T; while (T--) { solve(); }
}