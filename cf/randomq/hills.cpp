#include <bits/stdc++.h>

using namespace std;

const int P = 1e9 + 7;
template<class T> using vt = vector<T>;
template<int z> using ii = array<int, z>;

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vt<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    //we have to select houses that are not adjacent to be saved.
    //lets just select for one house. then it is easy.
    //make a dp to select k houses? dp[(i+1)/2][2] for each i
    //denoting # of houses selected + whether i itself is selected.
    //what about if [i-2] is selected? then we have to check...
    //so dp[(i+1)/2][4] where 0 and i-2 are unselected, 1 is i-1 selected (cant select)
    //2 is unselected but [i-2] is selected, 3 is both selected, 4 is just i is selected
    //[000] [010] [100] [101] [001]
    //[110] [011] [111] all excluded, what didn't i update right?
    //can apparently simplify to 2 states...
    vt<vt<int>> dp((N + 1) / 2 + 1, vt<int>(5, P));
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        auto ndp = vt((N + 1) / 2 + 1, vt(5, P));
        for (int j = 0; j <= (i + 2) / 2; j++) {
            //for [0]: previous must be unselected. [0] or [2]
            ndp[j][0] = min(dp[j][0], dp[j][2]);
            //for [1]: [3] or [4]
            //if we are >= [i-1] add a cost of height difference to cut ourselves
            int cost = (i > 0 && H[i] >= H[i-1] ? H[i] - H[i - 1] + 1 : 0);
            
            ndp[j][1] = cost + min(dp[j][3], dp[j][4]);

            //for [2]: [1]
            ndp[j][2] = dp[j][1];

            if (j > 0) { //we transition from j - 1
                //make the previous one shorter
                cost = (i > 0 && H[i-1] >= H[i] ? H[i-1] - H[i] + 1 : 0);
                //for [3] we transition from [1]. 
                if (i > 1) {
                    int bruh = (H[i-2] > H[i] ? H[i-2] - H[i] : 0); //to shorten further.
                    if (H[i] <= H[i-1] && H[i-1] < H[i-2] || H[i-1] < H[i]) {
                        ndp[j][3] = dp[j-1][1] + cost;
                    }   else {
                        ndp[j][3] = dp[j-1][1] + bruh;
                    }
                }
                
                //for [4] we transition from [0] or [2]
                ndp[j][4] = min(dp[j-1][0], dp[j-1][2]) + cost;
            }
        }
        dp.swap(ndp);
    }
    for (int i = 1; i <= (N + 1) / 2; i++) {
        int ans = P;
        for (int x : dp[i]) ans = min(x, ans);
        cout << ans << " \n"[i == (N + 1) / 2];
    }
}