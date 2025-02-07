#include <bits/stdc++.h>

#define vec vector

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    //lets see
    vec<vec<int>> table(N, vec<int>(N));
    vec<int> original(2 * N + 1);
    vec<bool> used(2 * N + 1);  //used in the final table
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> table[i][j];
            original[table[i][j]]++;
        }
    }
    cout << "\n";
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << i+ j << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 1; i <= 2 * N; i++) {
        cout << original[i] << " ";
    }
    cout << "\n";
    cout << "\n";
    //actually wtf is this oding
    vec<int> mapped(2 * N + 1);
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += original[table[i][j]];
            if (!mapped[table[i][j]]) {
                int freq = original[table[i][j]];
                //find the first number with freq = this
                int num = freq + 1;
                if (used[num]) { num = 2 * N - freq + 1; }
                mapped[table[i][j]] = num;
                used[num] = true;
            }
            cout << original[table[i][j]] << " ";
            table[i][j] = mapped[table[i][j]];
        }
        cout << sum << "\n";
    }
}