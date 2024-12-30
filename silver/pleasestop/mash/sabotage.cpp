#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    freopen("sabotage.in", "r", stdin);
    freopen("sabotage.out", "w", stdout);
    int N; cin >> N;
    //wow another binary search question??
    //one obvious strategy is that for each L where L is length
    //he should remove the subarray length L of max sum
    //OK its done
    //thats good for partials
    //why am i actually receiving brain damage from this
    //average problems are truly cancerous
    //just see if a certain average exists
    //we can't work for every single length
    //oh shoot
    //i do have brain damage but this is pretty dang hard
    cout << fixed << setprecision(3);
    int beglast; cin >> beglast;
    vector<int> rem(N - 2);
    for (int i = 0; i < N - 2; i++) {
        cin >> rem[i];
    }
    int x; cin >> x; beglast += x;
    double s = 0, e = beglast / 2.0, eps = 1e-6;
    while (s + eps < e) {
        vector<double> v(N - 2);
        double m = (s + e) / 2;
        for (int i = 0; i < N - 2; i++) {
            v[i] = rem[i] - m;
        }
        vector<double> pf(N - 1);
        for (int i = 0; i < N - 2; i++) {
            pf[i+1] = pf[i] + v[i];
        }
        double tot = beglast + pf[N - 2] - 2 * m;
        double minss = 0, maxss = 0;
        for (int i = 1; i < N - 1; i++) {
            maxss = max(pf[i] - minss, maxss);
            minss = min(minss, pf[i]);
        }
        if (tot - maxss < 0) { e = m; }
        else { s = m; }
    }
    cout << e << "\n";
}