#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N, M, K;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    //first take a graph as an exapmle
    //draw edges from distinct weights to other distinct weights where they are K away
    //what is optimal? this is greedy
    //stick as many cows on the first as possible, then next, and so on
    cin >> N >> M >> K;
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a *= -1;
        m[a] = b;
    }
    ll total = 0;  //might overflow?
    while (M != 0 && m.size() != 0) {
        pair<int, int> p = *m.begin();
        unordered_set<int> tower;
        int minfreq = p.second;
        tower.insert(p.first);
        while (m.lower_bound(p.first + K) != m.end()) {
            p = *(m.lower_bound(p.first + K));
            tower.insert(p.first);
            minfreq = min(minfreq, p.second);
        }
        if (minfreq > M) { total += M * tower.size(); M = 0; break; }
        total += minfreq * tower.size();
        M -= minfreq;
        while (!tower.empty()) {
            int a = *tower.begin();
            tower.erase(tower.begin());
            m[a] = m[a] - minfreq;
            if (m[a] == 0) { m.erase(a); }
        }
    }
    cout << total << "\n";
}