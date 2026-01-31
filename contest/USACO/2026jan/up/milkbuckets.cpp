#include <bits/stdc++.h>

using namespace std;
#define long int64_t //to make similar to java

struct segment_tree {
    int N;
    vector<int> d;
    segment_tree(int n): N(n), d(2 * n) {}

    void upd(int p, int v) {
        d[p + N] += v;
        for (p = (p + N) / 2; p; p >>= 1) 
            d[p] = d[2*p] + d[2*p+1];
    }
    int query(int l, int r) {
        int res = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += d[l++];
            if (r & 1) res += d[--r];
        }
        return res;
    }

};
void solve() {
    //cin reads the integer value in c++, equivalent to N = scanner.nextInt();
    int N; cin >> N;
    /*
    map is like treemap in java
    vector is the equivalent of an arraylist
    this stores for a milk amount, the positions in which it occurs in the array
    { milk amount, { arraylist of positions }}
     we can iterate over decreasing milk amount with this later.
    */
    map<int, vector<int>> m;
    vector<int> milk(N);
    for (int i = 0; i < N; i++) {
        cin >> milk[i];
        //push_back is equivalent to arraylist add
        m[milk[i]].push_back(i);
    }

    /*
    segment tree is a data structure that lets you find range sum (prefix sum)
    and point update (change the value of a point)
    in O(log N) time, where N is the size of the data.
    */
    segment_tree seg(N);
    long ans = 0;

    while (!m.empty()) {
        //*m.rbegin() gets last element, equivalent to 
        //TreeSet.lastEntry()
        auto [milkamt, positions] = *m.rbegin();
        m.erase(milkamt); //remove last key, so we can get next highest on the next iteration of the while loop
        int left_cand = 0, right_cand = positions.size() - 1;
        //these are buckets that have the same amount, in different positions
        //we start at the edges and pull them to the left or the right
        while (left_cand <= right_cand) {
            //just get the positions
            int left_pos = positions[left_cand], right_pos = positions[right_cand];
            //the cost for moving an index left is the index - # of removed positions
            //the cost for the rightmost is N - i - 1 - # of removed positions
            int leftcost = min(left_pos - seg.query(0, left_pos), N - left_pos - 1 - seg.query(left_pos, N));
            int rightcost = min(right_pos - seg.query(0, right_pos), N - right_pos - 1 - seg.query(right_pos, N));
            int select = -1; //the one we decide to remove.
            if (leftcost < rightcost) { //take the minimum cost
                select = left_pos;
                ans += leftcost;
                left_cand++; //move the left pointer up (we are done processing this one)
            }   else {
                select = right_pos;
                ans += rightcost;
                right_cand--; //move the right pointer down
            }
            seg.upd(select, 1);
        }
    }

    cout << ans << "\n";

}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    //test case
    int T; cin >> T; while (T --> 0) solve();
}