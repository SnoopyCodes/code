#include <bits/stdc++.h>
#define ll long long

using namespace std;
vector<int> cross;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N; cin >> N;
    cross.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cross[i];
    }
    string ans = "";
    bool right = true;  
    int r = N, l = -1;
    int cur = 0;
    while (cross[0] != 0) {  //is it forced to move past cur.5? it is not necessitated.
        if (right) {
            if (cur != r) {
                ans += "R";
                if (cross[cur] == 2) { l = cur; }
                cross[cur]--;
                cur++;
                right = !right;
                ans += "L";
                cur--;
                if (cross[cur] == 1) { r = cur; }
                cross[cur]--;
                cur--;
                if (r == l) {  
                    while (cur >= 0 && cross[cur] <= 1) {
                        if (cross[cur] == 1) { cross[cur]--; }
                        r = cur;
                        cur--;
                        ans += "L";
                    }
                    if (cur == -1) { break; }
                    l = cur;
                    while (l >= 0 && cross[l] > 1) {
                        l--;
                    }
                }
            }
        }   else {
            if (cur != l) {
                ans += "L";
                if (cross[cur] == 1) { r = cur; }
                cross[cur]--;
                cur--;
            }   else {
                right = !right;
                ans += "R";
                cur++;
                if (cross[cur] == 2) { l = cur; }
                cross[cur]--;
                cur++;               
            }
        }
    }
    cout << ans << "\n";
}