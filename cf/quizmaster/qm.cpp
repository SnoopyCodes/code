#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> smarts;
vector<int> factors;
vector<int> has;
void add(int student) {
    for (int i = 0; i < factors.size(); i++) {
        if (smarts[student] % factors[i] == 0) {
            has[i]++;
        }
    }
}
//okay this is wrong you cant use the prime factorization to justify having it all
int uses(int student) {  //how many factors this student contributes
    int num = 0;
    for (int i = 0; i < factors.size(); i++) {
        if (smarts[student] % factors[i] == 0 && has[i] == 1) {
            num++;
        }
    }
    return num;
}
void rem(int student) {
    for (int i = 0; i < factors.size(); i++) {
        if (smarts[student] % factors[i] == 0) {
            has[i]--;
        }
    }
}
void solve() {
    int N, M; cin >> N >> M;
    smarts.clear(); factors.clear(); has.clear();
    smarts.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> smarts[i];
    }
    sort(smarts.begin(), smarts.end());
    vector<bool> sieve(M+1);
    for (int i = 2; i <= M; i++) {
        if (sieve[i]) { continue; }
        //this is a prime
        int fac = i;
        while (fac * i <= M) { fac *= i; }
        factors.push_back(fac);
        for (int j = i * 2; j <= M; j += i) {
            sieve[j] = true;
        }
    }
    //okay factors obtained
    has.resize(factors.size());
    int j = 0;
    int numhas = 0;
    int ans = INT_MAX;
    if (M == 1) { cout << "0" << "\n"; return; }
    for (int i = 0; i < N; i++) {
        //its not guaranteed that the window size is always greater than 1
        add(i);
        numhas += uses(i);
        while (numhas == factors.size()) {  //if we are not double counting something, then my approach is just wrong?
            ans = min(ans, smarts[i] - smarts[j]);
            numhas -= uses(j);
            rem(j);
            j++;
        }
    }
    if (ans == INT_MAX) { cout << -1 << "\n"; }
    else { cout << ans << "\n"; }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}