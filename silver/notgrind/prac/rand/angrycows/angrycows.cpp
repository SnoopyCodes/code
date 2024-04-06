#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<int> cows;
set<int> s;
bool valid(double r, double insert) {
    double l = insert, are = insert;
    double lr = r, arer = r;
    while (l > *s.begin()) {
        double other = l - lr;
        if (s.lower_bound(other) == s.lower_bound(l)) { return false; }
        l = *s.lower_bound(other);
        lr--;
    }
    while (are < *--s.end()) {  //while we haevn't gotten to the end of the cows yet
        double other = are + arer;
        if (s.upper_bound(other) == s.upper_bound(are)) {
            return false;
        }
        are = *--s.upper_bound(other);
        arer--;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    // freopen("angry.in", "r", stdin);
    // freopen("angry.out", "w", stdout);
    int N; cin >> N;
    cows.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());
    //if we consider the distances between each of these cows, is the largest distance the only one we really need to consider?
    //what is the optimal placement for our cow?
    //if we can find the optimal placement and then binary search on optimal R with O(N) per explosion simulation then we are set
    //I don't see why it isn't binary search?
    //if its prefix sums then we can quickly use pfx to find the dist between different cows
    //then we can use a ?map? to quickly find what will engulf whedre
    //from there it takes O(N * 2 log N)? because N log N per simulation and log N for binary search?
    //wait but first where do we detonate our thing
    //it appears optimal to always throw it in the middle between the largest gap
    int g = 0;
    double centredist = INT_MAX, mid = (cows[0] + cows[N-1]) / 2.0;
    for (int i = 0; i < N - 1; i++) {
        if (cows[g+1]-cows[g] <= cows[i+1] - cows[i]) {
            double midp = (cows[i+1] - cows[i]) / 2.0 + cows[i];
            if (centredist > abs(midp - mid)) {
                g = i;
                centredist = abs(midp - mid);
            }
        }
        s.insert(cows[i]);
    }
    s.insert(cows[N-1]);
    double insert = cows[g] + (cows[g+1] - cows[g]) / 2.0;
    cout << insert << "\n";
    double start = 0, end = cows[N - 1] - cows[0]; //will most definitely cover
    while (end - start > 0.01) {
        double m = (start + end) / 2;
        if (valid(m, insert)) { end = m; }
        else { start = m; }
    }
    start *= 10;
    start = round(start);
    start /= 10;
    cout << fixed;
    cout << setprecision(1);
    cout << (double) start << "\n";
}