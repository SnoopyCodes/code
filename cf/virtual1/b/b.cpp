#include <bits/stdc++.h>

using namespace std;
void solve() {
    int N; cin >> N;
    //simulate process, check if at any time there are 2 diff things
    //wait hold on
    vector<int> candy(N);
    for (int i = 0; i < N; i++) {
        cin >> candy[i];
    }
    //uhhhh candy[i] = 0
    //wait i think it is just check if the top 2 differ by 1
    if (candy.size() < 2 && candy[0] != 1) { cout << "no" << "\n"; return; }
    else if (candy[0] == 1 && candy.size() == 1) { cout << "yes" << "\n"; return; }
    sort(candy.begin(), candy.end());
    if (candy[N-1] - candy[N-2] > 1) { cout << "no" << "\n"; }
    else { cout << "yes" << "\n"; }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while (T) { T--; solve(); }
}