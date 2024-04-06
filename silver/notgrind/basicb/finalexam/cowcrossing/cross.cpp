#include <bits/stdc++.h>

using namespace std;
vector<int> wake;
int N, M, C;
bool valid(int x) {
    //basically, set the intervals so that
    //they leave x after the next available cow slot
    int cow = 0;  //which cow we will wait on
    int used = 0;
    while (cow != wake.size()) {
        used++;
        int num = 1;  //covered
        while (cow + num != N && wake[cow+num] < wake[cow] + x) {
            num++;
        }
        if (num > C) { num = C; }  //can only cover C at a time
        if (cow + num == N) { return true; }  //we have covered it all
        if (used == M) { return false; }
        cow = cow + num;  //the next cow that we need to cover
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> C;
    wake.resize(N);
    for (int i = 0; i < N; i++) { cin >> wake[i]; }
    sort(wake.begin(), wake.end());
    //we can binary search on the wait time
    //and then just simulate from there
    //basically an easier version of firehose LOL
    int s = 0, e = 1e9+1;
    while (e > s + 1) {
        int m = (s + e) / 2;
        if (valid(m)) { e = m; }
        else { s = m; }
    }
    cout << s << "\n";
}