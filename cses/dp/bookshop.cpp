#include <bits/stdc++.h>

using namespace std;
int N, X;
vector<int> prices;
vector<int> pages;
vector<int> best;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> X;
    prices.resize(N+1);
    pages.resize(N+1);
    best.resize(X+1, -1);
    for (int i = 0; i < N; i++) {
        cin >> prices[i+1];
    }
    for (int i = 0; i < N; i++) {
        cin >> pages[i+1];
    }
    //we can N^2!!!!
    //okay so we can have books
    //wait is it not just hte ratio of pages per price
    //not quite
    //ah i have it
    //run knapsack
    //definitely a good idea
    //so basically store hte maximum number of pages you have in a thing
    //then what
    //each gift is once which actually complicates it 
    //uhh so basically for every one we want to see where we can move it up to
    //solve for using exactly
    //so best[i] means best[i] pages with first i
    //we are buying twice send help
    //
    best[0] = 0;
    for (int k = 1; k <= N; k++) {
        for (int sum = X; sum >= 0; sum--) {
            if (best[sum] != -1 && sum + prices[k] <= X) {
                best[sum + prices[k]] = max(best[sum + prices[k]], best[sum] + pages[k]);
            }
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 0; j <= X; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    int most = 0;
    for (int i = 1; i <= X; i++) {
        most = max(best[i], most);
    }
    cout << most;
}