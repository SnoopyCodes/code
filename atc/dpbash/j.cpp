#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    //say we choose some times
    //then each one is chosen about the same amount
    int N; cin >> N;
    cout << fixed << setprecision(10);
    vector<int> sushi(N);
    int one = 0, two = 0, three = 0;
    for (int i = 0; i < N; i++) {
        cin >> sushi[i];

    }
    //suppose we base it on how many sushis we eat
    vector<vector<vector<double>>> expect(one+1, vector<vector<double>>(two+1, vector<double>(three+1)));
    expect[0][0][0] = 1;

    for (int i = 0; i <= one; i++) {
        for (int j = 0; j <= two; j++) {
            for (int k = 0; k <= three; k++) {

            }
        }
    }

    cout << expect[one][two][three];
}