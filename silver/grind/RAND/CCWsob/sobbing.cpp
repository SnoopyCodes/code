#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct Patch {
    ll val, take;
};
vector<bool> visited;
bool comp(Patch p1, Patch p2) {
    return p1.val > p2.val;
}
vector<Patch> doubles;
vector<Patch> singles;
vector<pair<int, int>> patches;
vector<int> nhoj;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int K, M, N; cin >> K >> M >> N;
    patches.resize(K);
    nhoj.resize(M);
    visited.resize(K);
    for (int i = 0; i < K; i++) {
        int a, b;
        cin >> a >>  b;
        patches[i].first = a;
        patches[i].second = b;
    }
    for (int i = 0; i < M; i++) {
        cin >> nhoj[i];
    }
    cout << K << endl;
    int l = INT_MIN / 2;
    int loc = 0;
    for (int i = 0; i < M; i++) {  //we are before nhoji
        if (patches[loc].first == nhoj[i]) { loc++; }
        if (nhoj[i] < patches[loc].first) { continue; }  //any patch taken by nhoj is unclaimable
        int r = nhoj[i];
        ll sum = 0;
        int lp = loc;
        int md = (r - l) / 2 + l;
        int ld = patches[loc].first - l;
        while (loc != K && patches[loc].first < r) { sum += patches[loc].second; loc++; }
        loc--;
        int rd = r - patches[loc].first;
        //any one cow things are easy
        if (md - patches[lp].first < ld && patches[loc].first - md < rd) {  //just make a 1
            Patch p = {sum * 2, i};
            doubles.push_back(p);
        }   else {  //find the max single cow sum
            doubles.push_back({sum, i});
            ll sum1 = 0, sum2 = 0;
            while (patches[lp].first - l < ld) { sum1 += patches[lp].second; lp++; }
            while (r - patches[loc].first < rd) { sum2 += patches[loc].second; loc--; }
            ll sum0 = max(sum1, sum2);
            singles.push_back({sum0 * 2, i});
        }
    }
    sort(singles.begin(), singles.end(), comp);
    sort(doubles.begin(), doubles.end(), comp);
    int s = 0, d = 0;
    ll total = 0;
    while (N > 0) {
        while (s < singles.size() && visited[singles[s].take]) { s++; }
        while (d < doubles.size() && visited[doubles[s].take]) { d++; }
        if (N == 1) {
            if (s != singles.size()) {
                total += singles[s].val;
                s++;
                N--;
            }
        }   else {
            if (s == singles.size() && d == doubles.size()) { break; }
            if (d == doubles.size()) {
                total += singles[s].val;
                visited[singles[s].take] = true;
                s++;
            }   else if (s == singles.size()) {
                total += doubles[d].val;
                visited[doubles[d].take] = true;
                d++;
            }   else {
                if (singles[s].val > doubles[d].val) {
                    total += singles[s].val / 2;
                    visited[singles[s].take] = true;
                    s++;
                    N--;
                }   else {
                    total += doubles[d].val;
                    visited[doubles[d].take] = true;
                    d++;
                    N -= 2;
                }
            }
        }
    }
    cout << total;
}