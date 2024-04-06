#include <bits/stdc++.h>

using namespace std;

vector<int> students;
vector<int> factors;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int n; cin >> n;
        int m; cin >> m;
        students.resize(n);
        factors.resize(m);
        long long lc = m;
        for (int i = 2; i < m; i++) {
            lc = lcm(lc, i);
        }
        for (int i = 0; i < n; i++) {
            cin >> students[i];
        }
        sort(students.begin(), students.end());
        int l = 0, r = 0;
        long long prod = 1;
        //the idea is that when the product of l through r % lc == 0 we have succeeded
        //ok so for i through 
        int mindist = INT_MAX;
        bool works = false;
        while (r != n) {
            prod *= students[r];
            if (prod % lc == 0) { works = true; mindist = min(r - l, mindist); }
            if (works) {
                while (l != n && (prod / students[l]) % lc == 0) {
                    prod /= students[l];
                    l++;
                }
                mindist = min(r-l, mindist);
            }
            r++;
        }
        if (mindist == INT_MAX) { cout << -1 << "\n"; }
        else { cout << mindist << "\n"; }
    }
//so we can first find all the primes that we need to be proficient in
//at the very least the lcm of all from 1-m must be achieved.
//ok so we need to first find the lcm of all the topics
}