#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int, int>> patches;
vector<int> nhoj;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int K, M, N; cin >> K >> M >> N;
    patches.resize(K);
    nhoj.resize(M);
    for (int i = 0; i < K; i++) { cin >> patches[i].first >> patches[i].second; }
    for (int i = 0; i < M; i++) { cin >> nhoj[i]; }
    sort(patches.begin(), patches.end());
    sort(nhoj.begin(), nhoj.end());
    priority_queue<pair<ll, int>> yum;  //we want the largest intervals with the least amount of cows, so we will input 2 cows as val, 1 and 1 as val, 2
    int patch = 0;  //find how many patches
    ll cost = 0;
    while (patches[patch].first < nhoj[0]) {
        cost += patches[patch].second;
        patch++;
    }
    //check if a placement is valid
    if (nhoj[0] != 0) {
        cost *= 2;
        yum.push({cost, 2});
    }
    cout << "\n";
    cout << patch << "\n";
    for (int i = 1; i < M; i++) {  //the interval between i-1 and i
        while (patch != K && patches[patch].first == nhoj[i]) { patch++; }  //we dont like these bc theyre impossible
        if (patch == K) { break; }
        cost = 0;
        //find first dist
        int fdist = patches[patch].first - nhoj[i-1];
        int init = patch;
        int mdist = 0;  //distance between first and last patch we cover
        int ldist = 0;
        while (patch != K && patches[patch].first < nhoj[i]) {
            if (patch == 1) { cout << patches[patch].first << " " << patches[patch].second << "\n";}
            cost += patches[patch].second;
            mdist = patches[patch].first - patches[init].first;
            ldist = nhoj[i] - patches[patch].first;
            patch++;
        }
        cout << init << " " << patch << "\n";
        if (patch == init) { continue; }  //dont do anything here, blank interval
        //find if we can cover with just 1 cow
        if (mdist / 2.0 < fdist && mdist / 2.0 < ldist) {
            yum.push({2 * cost, 1});  //okay so it correctly adds now
            cout << "hi" << "\n";
            cout << fdist << " " << mdist << " " << ldist << "\n";
            cout << patches[init].first << " " << nhoj[i] << "\n";
        }   else {
            //check if its possible at all
            //it really should only be impossible if they are sitting on a patch
            yum.push({cost, 2});
        }
    }
    cost = 0;
    while (patch != K) {
        cost += patches[patch].second;
        patch++;
    }
    if (cost != 0) { yum.push({2 * cost, 2}); }
    ll total = 0;
    cout << yum.size() << "\n";
    cout << "\n";
    while (N != 0 && !yum.empty()) {
        cout << yum.top().first << " " << yum.top().second << "\n";
        if (N == 1) {
            while (!yum.empty() && yum.top().second != 2) { yum.pop(); }
            if (yum.empty()) { break; }
            total += yum.top().first / 2;
            N--;
            continue;
        }
        pair<ll, int> p = yum.top();
        yum.pop();
        if (p.second == 1) {
            total += p.first / 2;
            N--;
        }   else {
            total += p.first;
            N--; N--;
        }
    }
    cout << total << "\n";
}