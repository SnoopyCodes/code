#include <bits/stdc++.h>

using namespace std;
vector<int> cows;
vector<int> maxes;
vector<int> ud;
vector<pair<int, int>> known;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    for (int t = 0; t < T; t++) {
        int N, Q, C; cin >> N >> Q >> C;
        cows.clear(); cows.resize(N);
        known.resize(Q);
        maxes.resize(N);
        int maxs = 1;
        for (int i = 0; i < N; i++) {
            cin >> cows[i];
            if (cows[i] == 0) { ud.push_back(i); }
            maxs = max(cows[i], maxs);
            maxes[i] = maxs;
        }
        for (int i = 0; i < Q; i++) {
            cin >> known[i].first >> known[i].second;
            known[i].first--;
            known[i].second--;
        }
        sort(known.begin(), known.end());
        bool valid = true;
        int used = -1;  //
        int maxput = 1;  //the highest value from 0 to a
        int c = 0;
        for (int i = 0; i < Q; i++) {
            int a = known[i].first, h = known[i].second;
            while (c <= a) { maxput = max(maxput, cows[c]); c++; }
            //now find the last ud
            //binary search on the largest ud <= a
            int s = used+1, e = ud.size();
            while (e > s+1) {
                int m = (s + e) / 2;
                if (ud[m] > a) { e = m; }
                else { s = m; }
            }
            int fidk = ud[s];
            if (fidk <= a) {  //comes from outside?
                used = fidk;
                if (maxes[h-1] > maxput) {
                    cows[fidk] = maxes[h-1];
                    maxput = cows[fidk];
                }
            }
            if (maxes[h-1] > maxput) { valid = false; break; }
            if (cows[h] == 0) {
                cows[h] = max(maxes[h-1], maxput) + 1;
                if (cows[h] > C) { valid = false; break; }
            }
            else {
                if (cows[h] < max(maxes[h-1], maxput)) { valid = false; break; }
            }
        }
        //recompute the thing and just check
        maxs = 1;
        for (int i = 0; i < N; i++) {
            maxs = max(cows[i], maxs);
            maxes[i] = maxs;
        }
        for (int i = 0; i < Q; i++) {
            int a = known[i].first, h = known[i].second;
            if (maxes[h-1] > maxes[a]) { valid = false; }
            if (h < maxes[h-1]) { valid = false; }
        }
        if (!valid) {
            cout << -1 << "\n";
        }   else {
            for (int i = 0; i < N-1; i++) {
                if (cows[i] == 0) { cows[i] = 1; }
                cout << cows[i] << " ";
            }
            if (cows[N-1] == 0) { cows[N-1] = 1; }
            cout << cows[N-1];
            cout << "\n";
        }
    }
}