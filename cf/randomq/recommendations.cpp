#include <bits/stdc++.h>

using std::vector, std::array, std::min, std::max, std::cin, std::cout, std::swap;

#define long long long
#define max_heap std::priority_queue

const int MOD = 1e9 + 7;
const long INF = 4e18;

void solve() {
    //bruh.
    int N; cin >> N;
    vector<array<int, 3>> users(N);
    for (int i = 0; i < N; i++) {
        cin >> users[i][0] >> users[i][1];
        users[i][2] = i;
    }
    //iterate left to right
    //when we enter an interval, query for the shortest range 
    //less and greater
    //sort by shortest begin, farthest end point
    sort(users.begin(), users.end(), [](auto a, auto b) {
        if (a[0] == b[0]) { return a[1] > b[1]; }
        return a[0] < b[0];
    });

    vector<bool> dupe(N);
    vector<int> ans(N), right(N);
    std::set<int> borders;
    for (int i = 0; i < N; i++) {
        if (i + 1 < N && users[i][0] == users[i+1][0] && users[i][1] == users[i+1][1]) {
            dupe[users[i+1][2]] = true;
            dupe[users[i][2]] = true;
            
            continue;
        }
        //if it is dupe, it can have none
        //we can find the shortest right element that contains it.
        //thus, if we reverse it, we can find the largest left element
        while (!borders.empty() && *borders.begin() < users[i][0]) { borders.erase(borders.begin()); }
        if (borders.lower_bound(users[i][1]) != borders.end()) {
            right[users[i][2]] = *borders.lower_bound(users[i][1]);
        }
        borders.insert(users[i][1]);
    }
    //shortest end, farthest begin
    std::sort(users.begin(), users.end(), [](auto a, auto b) {
        if (a[1] == b[1]) { return a[0] > b[0]; }
        return a[1] < b[1];
    });
    borders.clear();
    for (int i = N - 1; i > -1; i--) {
        while (!borders.empty() && *borders.begin() > users[i][1]) { borders.erase(borders.begin()); }
        if (!borders.empty() && *--borders.upper_bound(users[i][0]) <= users[i][0]) {
            int left = *--borders.upper_bound(users[i][0]);
            if (dupe[users[i][2]]) { ans[users[i][2]] = 0; }
            else {
                ans[users[i][2]] = max(0, right[users[i][2]] - left + 1 - (users[i][1] - users[i][0] + 1));
            }
        }
        borders.insert(users[i][0]);
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}