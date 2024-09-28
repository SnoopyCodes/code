#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int N; cin >> N;
    vector<vector<bool>> field(N, vector<bool>(N));
    vector<vector<int>> traffic(N, vector<int>(N, 1));
    vector<int> vert(N);
    vector<int> hor(N);
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < N; j++) {
            //1 is down, 0 is right
            field[i][j] = s[j] == 'D';
        }
        cin >> hor[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> vert[i];
    }
    
    //also, calculate for each cell the initial cows that go through it
    //then we can follow paths
    long long ans = 0;  //probably fine, but just in case
    //1500 * 1500 = 2250000, = 2e7, *500 -> too much
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (field[i][j]) {
                if (i == N - 1) {
                    ans += (long long) vert[j] * traffic[i][j];
                }   else {
                    traffic[i+1][j] += traffic[i][j];
                }
            }   else {
                if (j == N - 1) {
                    ans += (long long) hor[i] * traffic[i][j];
                }   else {
                    traffic[i][j+1] += traffic[i][j];
                }
            }
        }
    }
    cout << ans << "\n";
    int Q; cin >> Q;
    auto trace = [&](int r, int c, int vol) {
        while (r != N && c != N) {
            traffic[r][c] += vol;
            if (field[r][c]) { r++; }
            else { c++; }
        }
        return r == N ? vert[c] : hor[r];
    };
    for (int q = 0; q < Q; q++) {
        int r, c; cin >> r >> c; r--; c--;
        int vol = traffic[r][c];  //current
        if (field[r][c]) {  //subtract down, add right
            ans -= (long long) vol * trace(r + 1, c, -vol);
            ans += (long long) vol * trace(r, c + 1, vol);
        }   else {  //add down, subtract right
            ans += (long long) vol * trace(r + 1, c, vol);
            ans -= (long long) vol * trace(r, c + 1, -vol);
        }
        field[r][c] = !field[r][c];
        cout << ans << "\n";
    }
}