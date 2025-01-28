#include <bits/stdc++.h>

using namespace std;

vector<int> val;

int main() {
    int N, K; cin >> N >> K;
    val.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }
    sort(val.begin(), val.end());
    double s = 0, e = 1, eps = 1e-9;
    long long ans = 0;
    //binary search for minimum fraction with at least k <= it
    while (s + eps < e) {
        double m = (s + e) / 2;
        //count p/q < m
        //p < m * q
        int cnt = 0;
        vector<int> closest(N);
        for (int i = 1; i < N; i++) {
            //next binary search
            //val[i] = q
            //find maximum p <= m * q
            if (upper_bound(val.begin(), val.end(), m * val[i]) == val.end()) { closest[i] = -1; continue; }
            closest[i] = upper_bound(val.begin(), val.end(), m * val[i]) - val.begin();
            cnt += closest[i]; closest[i]--;
        }
        if (cnt < K) {
            s = m;
        }   else {
            e = m;
            //find the largest fraction < m
            int best = N - 1;
            for (int i = 1; i < N; i++) {
                //again p <= m * q
                if (closest[i] == -1) { continue; }
                double diff = m - (double) val[closest[i]] / val[i];
                double bdiff = m - (double) val[closest[best]] / val[best];
                if (diff < bdiff) { best = i; }
            }
            ans = (long long) val[closest[best]] * 100000 + val[best];
        }
    }
    cout << ans << endl;
}
