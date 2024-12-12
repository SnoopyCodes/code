#include <bits/stdc++.h>
#define long int64_t
using namespace std;

vector<array<long, 3>> F;
int N, C, M;

bool valid(int g) {
    long minx = max(0, -(M - g - 1)), maxx = min(g, C - 1);
    for (auto [a, b, t] : F) {
        long left = C * a +  M * b - b * g - t;
        //what if a = b? it is valid iff Ca + Mb - bg <= t
        if (a == b) { if (left > 0) { return false; } continue; }
        if (a > b) {  //perform ceiling division
            //if left is less than zero then we don't care
            minx = max(minx, (left - 1) / (a - b) + 1);
        }   else {
            if (left < 0) {  //
                maxx = min(maxx, left / (a - b));
            }   else {
                //we have to return false here why?
                //maxx guaranteed <= 0 so not possible?
                //because this states that 0 is possible at this point when it isn't
                //bruhhh what a case jesus
                return false;
            }
        }
    }
    return minx <= maxx;
}

void solve() {
	cin >> N >> C >> M;
    F.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> F[i][0] >> F[i][1] >> F[i][2];
    }
    int s = -1, e = C + M - 1;
    while (s + 1 < e) {
        int m = s + (e - s) / 2;
        if (valid(m)) { e = m; }
        else { s = m; }
    }
    cout << e << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
	int T; cin >> T; while (T--) { solve(); }
}