#include <bits/stdc++.h>

using namespace std;
struct py {
    int p, c, x;
};
vector<py> pyq;
bool cmp(py py1, py py2) {
    return py1.x < py2.x;
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N, A, B; cin >> N >> A >> B;
    pyq.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> pyq[i].p >> pyq[i].c >> pyq[i].x;
    }
    sort(pyq.begin(), pyq.end(), cmp);
    vector<vector<int>> pop(N + 1, vector<int>(A + B + 2, -1));
    //okay so dp[i][j] where j <= A means
    //the amount of moonie we have spent
    //at this point we cannot spend anymore ice cream cones
    //so we should consider whether to buy it or not
    pop[0][A + 1] = 0;
    // cout << "\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < A + 1; j++) {
            if (i != 0) { pop[i][j] = max(pop[i-1][j], pop[i][j]); }
            if (pop[i][j] == -1) { continue; }

            if (j + pyq[i].c <= A)
            pop[i + 1][j + pyq[i].c] = max(pop[i + 1][j + pyq[i].c], pop[i][j] + pyq[i].p);
        }
        for (int j = A + 1; j < A + B + 2; j++) {
            if (i != 0) { pop[i][j] = max(pop[i-1][j], pop[i][j]); }
            if (pop[i][j] == -1) { continue; }

            int amt = B - (j - A - 1);
            //we should eat the maximum amount possible of ice cream cones
            if (amt < pyq[i].c * pyq[i].x) {  //we can't buy it all
                int buy = amt / pyq[i].x;
                if (pyq[i].c - buy <= A)
                pop[i + 1][pyq[i].c - buy] = max(pop[i + 1][buy], pop[i][j] + pyq[i].p);
            }   else {  //we can buy it all, hoorays!
                int spent = pyq[i].c * pyq[i].x;
                if (j + spent < A + B + 2)
                pop[i + 1][j + spent] = max(pop[i + 1][j + spent], pop[i][j] + pyq[i].p);
            }
        }
    }
    // for (int i = 0; i < N + 1; i++) {
    //     for (int j = 0; j < A + B + 2; j++) {
    //         cout << pop[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int ans = 0;
    for (int i = 0; i < A + B + 2; i++) {
        pop[N][i] = max(pop[N-1][i], pop[N][i]);
        ans = max(ans, pop[N][i]);
    }
    cout << ans << endl;
}