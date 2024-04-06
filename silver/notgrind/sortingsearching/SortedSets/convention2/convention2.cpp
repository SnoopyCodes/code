#include <bits/stdc++.h>

using namespace std;


struct Cow {
    int seniority, arrive, length;
    bool operator<(const Cow& c) const { return seniority < c.seniority; }
};

bool cmp(const Cow& c1, const Cow& c2) {
    if (c1.arrive == c2.arrive) { return c1.seniority > c2.seniority; }
    return c1.arrive < c2.arrive; 
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);
    int N;
    cin >> N;
    vector<Cow> v(N);
    for (int i = 0; i < N; i++) {
        v[i].seniority = N - i;
        cin >> v[i].arrive >> v[i].length;
    }
    sort(begin(v), end(v), cmp);
    priority_queue<Cow> pq;
    int wait = 0;
    int time = 0;
    
    for (int i = 0; i <= N; i++) {
        int arrival;
        if (i != N) { arrival = v[i].arrive; }
        else { arrival = INT_MAX; }
        while (!pq.empty() && time < arrival) {
            Cow c = pq.top();
            pq.pop();
            wait = max(wait, time - c.arrive);
            time += c.length;
        }
        if (i == N) { break; }
        time = max(time, arrival); 
        pq.push(v[i]);
    }
    cout << wait;
    return 0;
}