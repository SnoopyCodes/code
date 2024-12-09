#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
	int N, P; cin >> N >> P;
	vector<array<int, 4>> spring(P);
	for (int i = 0; i < P; i++) {
		cin >> spring[i][0] >> spring[i][1] >> spring[i][2] >> spring[i][3];
	}
	//add endpoints, 0,0 initially
	//sort boards
	sort(spring.begin(), spring.end());
	map<int, int> m; //y, save
	set<array<int, 3>> s;
	m[0] = 0;
	for (int i = 0; i < P; i++) {
		//add the ones that we should add
		while (!s.empty() && (*s.begin())[0] <= spring[i][0]) {
			auto [x, y, v] = *s.begin(); s.erase(s.begin());
			auto it = --m.upper_bound(y);
            if (it->second >= v) { continue; }
            it++;
			m[y] = max(m[y], v);
			while (it != m.end() && (*it).second <= v) {
				it = m.erase(it);
			}
		}
		//find maximum in save
		int amt = (*--m.upper_bound(spring[i][1])).second;
		amt += spring[i][2] - spring[i][0] + spring[i][3] - spring[i][1];
		s.insert({spring[i][2], spring[i][3], amt});
	}
    while (!s.empty()) {
        auto [x, y, v] = *s.begin(); s.erase(s.begin());
        auto it = --m.upper_bound(y);
        if (it->second >= v) { continue; }
        it++;
        m[y] = max(m[y], v);
        while (it != m.end() && (*it).second <= v) {
            it = m.erase(it);
        }
    }
	cout << 2 * N - (*--m.end()).second << "\n";
}