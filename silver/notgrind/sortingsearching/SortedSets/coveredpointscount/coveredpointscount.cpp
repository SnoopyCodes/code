#include <bits/stdc++.h>

using namespace std;

struct Point {
    long long x; bool end;
    bool operator<(const Point& p) const {
        if (x == p.x) { return end; }
        return x > p.x;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> v(n+1);
    priority_queue<Point> pq;
    for (int i = 0; i < n; i++) {
        Point p1;
        Point p2;
        cin >> p1.x >> p2.x;
        p1.end = false; p2.end = true;
        pq.push(p1);
        pq.push(p2);
    }
    int on = 0;
    long long prev = 0;
    while (!pq.empty()) {
        Point p = pq.top();
        pq.pop();
        v[on] += p.x - prev - 1;
        if (!p.end) { on++; }
        while (!pq.top().end && pq.top().x == p.x) {
            on++;
            pq.pop();
        }
        v[on]++;
        while (!pq.empty() && pq.top().x == p.x) {
            on--;
            pq.pop();
        }
        if (p.end) { on--; }
        prev = p.x;
    }
    for (int i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }
}