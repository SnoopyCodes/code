#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, K; cin >> N >> K;
    string s; cin >> s;
    vt<double> oz(N);
    for (int i = 0; i < N; i++) {
        oz[i] = s[i] == 'o' ? 1 : 0;
    }
    double lo = (double) K / N;
    double hi = 1;

    double eps = 1e-9;
    while (lo + eps < hi) {
        double mid = (lo + hi) / 2;
        vt<double> cur(N);
        for (int i = 0; i < N; i++) {
            cur[i] = oz[i] - mid;
        }


        //if the maximum subarray sum of at least k weighted pts behind, possible avg.
        double min_k_behind = 0;
        bool can = false;
        int wins = 0;
        vt<double> pf(N + 1);
        int j = 0;
        int jwins = 0;
        for (int i = 0; i < N; i++) {
            pf[i + 1] = pf[i] + cur[i];
            wins += oz[i];


            if (wins >= K) {
                while (jwins + oz[j] <= wins - K) {
                    jwins += oz[j];
                    j++;
                    min_k_behind = min(min_k_behind, pf[j]);
                }
                if (pf[i + 1] - min_k_behind >= 0) {
                    can = true;
                }
            }
        }
        (can ? lo : hi) = mid;
    }
    printf("%.10f", lo);
}