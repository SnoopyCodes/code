#include <bits/stdc++.h>
using namespace std;

struct Edge {
	int a, b, w;
	bool operator<(const Edge &y) const { return w < y.w; }
};

int main() {
	int M = 4;
	vector<Edge> v;
	for (int i = 0; i < M; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		v.push_back({a, b, w});
	}
	sort(begin(v), end(v));
	priority_queue<Edge> pq;
	pq.push(v[0]);
	for (Edge e : v) cout << e.a << " " << e.b << " " << e.w << "\n";
}