#include <bits/stdc++.h>

using namespace std;

/*
fix the base. by this i mean iterate rows from 0 and only consider processed rows in terms of columns.
imagine for a position (r, c) the rectangles that can be formed 
with it as its left corner. find the columns to the left that are of the same color
if the column to the left is smaller, it is simply answer of column to the left + height of this one
if the columnt to the right is taller, we can only form with current height.
so find the leftmost smaller one.
*/

#define long long long
template<class T> using vt = vector<T>;

void solve() {
    int R, C; cin >> R >> C;
    vt<int> prev(C + 1);
    vt<int> top_same(C + 1);

    long ans = 0;
    for (int i = 0; i < R; i++) {
        int cur = -1;
        int start = 0;
        vt<long> res(C + 1);
        vt<int> next_smaller(C);
        for (int j = 0; j <= C; j++) {
            int x;
            if (j < C) { cin >> x; }
            else { x = 0; } //force process the last block.

            if (prev[j] == x) {
                top_same[j]++;
            }   else {
                top_same[j] = 1;
                prev[j] = x;
            }
            
            if (j == 0) { cur = x; start = j; }
            else if (cur != x) { //process the block.
                //find the next smaller element.
                //the answer for this square is res[next_smaller] + top_same[k] * (k - next_smaller)
                for (int k = start; k < j; k++) {
                    int l = k - 1;
                    while (l != start - 1 && top_same[k] <= top_same[l]) { l = next_smaller[l]; }
                    next_smaller[k] = l;

                    res[k] += top_same[k] * (k - next_smaller[k]);
                    if (next_smaller[k] != start - 1) { res[k] += res[next_smaller[k]]; }
                    ans += res[k];
                }

                cur = x;
                start = j;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int T; cin >> T; while(T--) { solve(); }
}